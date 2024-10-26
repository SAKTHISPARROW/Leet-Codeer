import time
import logging

import fastapi
from fastapi.middleware.cors import CORSMiddleware
from fastapi import Request, Response, status, WebSocket, WebSocketDisconnect

from bus import Bus
from ticket import Ticket
from passenger import Passenger
from admin import Admin
from seat import Seat
from user import User
from models.models import TicketModel, VisitorDetail, BusModel, MergeModel

import loghandler
from utils import info_log, error_log

app = fastapi.FastAPI(threading=True)

app.add_middleware(
    CORSMiddleware,
    allow_origins=['*'],
    allow_credentials=True,
    allow_methods=['*'],
    allow_headers=['*'],
)


class ConnectionManager:
    def __init__(self):
        self.connections: list[WebSocket] = []

    async def add_connection(self, websocket: WebSocket):
        await websocket.accept()
        self.connections.append(websocket)

    def remove_connection(self, websocket: WebSocket):
        self.connections.remove(websocket)

    async def broadcast(self, message: MergeModel):
        for conn in self.connections:
            await conn.send_json(message.model_dump_json())


connection_manager = ConnectionManager()


@app.websocket("/ws/mergestatus")
async def websocket_endpoint(websocket: WebSocket):
    await connection_manager.add_connection(websocket)
    try:
        while True:
            data = await websocket.receive_json()
            await connection_manager.broadcast(data)
    except WebSocketDisconnect:
        connection_manager.remove_connection(websocket)


logging.basicConfig(
    filename='logs.log',
    filemode='a',
    level=logging.DEBUG
)
logger = logging.getLogger(__name__)


@app.middleware('http')
async def log(request: Request, call_next):
    response = await call_next(request)
    response_body = b""

    async for chunk in response.body_iterator:
        response_body += chunk

    log_msg = {
        "host": request.url.hostname,
        "port": request.url.port,
        "endpoint": request.url.path,
        "response": response_body.decode(),
    }
    logger.debug(log_msg)

    ip = request.client.host
    time_ = time.strftime("%Y-%m-%d %H:%M:%S")
    loghandler.insert_log(ip, time_)

    return Response(
        content=response_body,
        status_code=response.status_code,
        headers=dict(response.headers),
        media_type=response.media_type
    )


@app.get('/', status_code=status.HTTP_200_OK)
def index(date: str = "2024-02-16"):
    buses = [id_[0] for id_ in Bus.get_all_by_date(date)]
    if not buses:
        for i in range(1, Bus.INITIAL_BUS + 1):
            Bus.add_for_date(i, date)
    buses = [id_[0] for id_ in Bus.get_all_by_date(date)]
    return buses


@app.post('/user', status_code=status.HTTP_201_CREATED)
def add_user(username: str, password: str):
    return User.add(username, password)


@app.get('/user')
def authenticate_user(username: str, password: str):
    return User.authenticate(username, password)


@app.get('/passenger/{username}/all')
def get_passengers(username: str):
    res = Passenger.get_all_by_username(username)
    passengers = [Passenger.map_passenger(x) for x in res]
    return passengers


@app.get('/passenger/{username}', status_code=status.HTTP_200_OK)
def get_passengers_for_seats(response: Response, username: str, date: str, bus_id: int):
    try:
        res = Passenger.get_all_by_username_for_seats(username, date, bus_id)
        passengers = [Passenger.map_passenger(x) for x in res]
        return passengers
    except Exception as e:
        err_msg = f"Passenger seat query failed for {username} on {date} for bus {bus_id}"
        error_log(logger, e, err_msg)
        response.status_code = status.HTTP_404_BAD_REQUEST
        return None


@app.get('/passenger')
def get_passenger(passenger_id):
    return Passenger.get_by_id(passenger_id)


@app.post('/passenger', status_code=status.HTTP_201_CREATED)
def add_passenger(response: Response, name, username, gender='U'):
    try:
        return Passenger.add(name, username, gender)
    except Exception as e:
        response.status_code = status.HTTP_400_BAD_REQUEST
        return {"error": e}


@app.put('/passenger', status_code=status.HTTP_201_CREATED)
def update_passenger(passenger_id, name):
    return Passenger.update_by_id(passenger_id, name)


@app.delete('/passenger')
def delete_passenger(passenger_id):
    return Passenger.delete(passenger_id)


@app.get('/bus/{id}')
def get_bus(id, date):
    bus_ = Bus.get_by_id(id)
    if bus_ is None:
        return {"error": "Bus not found"}

    available_seats = [x[0] for x in Bus.get_available_seats(id, date)]
    booked_seats = [x[0] for x in Bus.get_booked_seats(id, date)]
    load_factor = Bus.get_load_factor(id, date)

    return {
        "id": bus_[0],
        "total_seats": bus_[1],
        "available_seats": available_seats,
        "booked_seats": booked_seats,
        "load_factor": load_factor
    }


@app.post('/bus', status_code=status.HTTP_201_CREATED)
def add_bus(id, total_seats):
    return Bus.add(id, total_seats)


@app.delete('/bus/{id}')
def delete_bus(id):
    return Bus.delete_by_id(id)


@app.get('/ticket/{id}')
def get_ticket(id):
    return Ticket.get_by_id(id)


@app.get('/ticket/all/{username}')
def get_tickets(username):
    res = Ticket.get_user_tickets(username)
    tickets = [Ticket.map_ticket(x) for x in res]
    return tickets


@app.delete('/ticket/{ticket_id}')
def cancel_ticket(ticket_id, response: Response):
    res = Ticket.cancel_ticket(ticket_id)
    try:
        message = res["error"]
        _msg = message + f" Ticket {ticket_id} not found"
        error_log(logger, message)
        response.status_code = status.HTTP_404_NOT_FOUND
    except KeyError:
        pass
    return res


@app.post('/bus/{bus_id}/book', status_code=status.HTTP_201_CREATED)
async def book(tickets: list[TicketModel], response: Response):
    res = await Ticket.payment(tickets)
    try:
        message = res["error"]
        error_log(logger, res, message)
        response.status_code = status.HTTP_400_BAD_REQUEST
    except TypeError:
        try:
            message = res[0]["error"]
            error_log(logger, res, message)
            response.status_code = status.HTTP_400_BAD_REQUEST
        except KeyError:
            info_log(logger, res)
    return res


@app.delete('/bus/{ticket_id}/cancel')
def cancel(ticket_id: int):
    return Ticket.cancel_ticket(ticket_id)


@app.delete('/bus/cancel/{bus_id}')
def cancel_ticket(bus_id: int, seat_id: int, date: str, username: str, response: Response):
    ticket_id = Ticket.get_ticket_id(bus_id, seat_id, date)[0]
    ticket = Ticket.map_ticket(Ticket.get_by_id(ticket_id))
    if Passenger.get_username(ticket["passenger_id"]) == username:
        return Ticket.cancel_ticket(ticket_id)

    response.status_code = status.HTTP_403_FORBIDDEN
    response.body = "You do not have permission to cancel"
    return {"error": "You do not have permission to cancel the ticket"}


@app.get('/admin/login')
def admin_(username: str, password: str):
    return Admin.authenticate(username, password)


@app.post('/admin/add', status_code=status.HTTP_201_CREATED)
def add_admin(username: str, password: str):
    return Admin.add(username, password)


@app.get('/admin/visitors/all')
def get_visitors():
    res = loghandler.get_by_dates()
    response = [VisitorDetail(date=x[0], visitor_count=x[1]) for x in res]
    return response


@app.get('/admin/visitors/{date}')
def get_visitor_by_date(date):
    return loghandler.get_by_date(date)[0]


@app.get('/admin/bus/all')
def get_all_buses():
    buses = Bus.get_all()
    response = [BusModel(id=x[0], total_seats=x[1]) for x in buses]
    return response


@app.get('/admin/bus/mergecandidates')
def get_merge_candidates(date):
    return Admin.merge_candidates(date)


@app.post('/admin/bus/merge')
async def merge_buses(date, bus1, bus2):
    Admin.set_merge_status(bus1, date)
    Admin.set_merge_status(bus2, date)
    await connection_manager.broadcast(MergeModel(bus1_id=bus1, bus2_id=bus2, date=date))
    res = await Admin.merge_buses(date, bus1, bus2)
    if res:
        Admin.reset_merge_status(bus1, date)
        Admin.reset_merge_status(bus2, date)
    return res


@app.get('/admin/bus/mergestatus')
def get_merge_status(bus_id, date):
    return Admin.get_merge_status(bus_id, date)


@app.post('/admin/bus/add', status_code=status.HTTP_201_CREATED)
def add_bus(bus_id, total_seats):
    return Bus.add(bus_id, total_seats)


@app.delete('/admin/bus/delete')
def delete_bus(bus_id):
    return Bus.delete_by_id(bus_id)


@app.post('/checkbeingbooked')
def check_being_booked(date, bus_id, seat_ids: list[int]):
    return Seat.is_being_booked(seat_ids, bus_id, date)


@app.post('/beingbooked/set')
def set_is_being_booked(date, bus_id, seat_ids: list[int]):
    return Seat.set_is_being_booked(seat_ids, bus_id, date)


@app.post('/beingbooked/reset')
def reset_is_being_booked(date, bus_id, seat_ids: list[int]):
    return Seat.reset_is_being_booked(seat_ids, bus_id, date)
