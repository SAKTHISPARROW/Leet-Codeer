from pydantic import BaseModel
import datetime


class TicketModel(BaseModel):
    bus_id: int
    seat_id: int
    passenger_id: int
    date: str
    lock: bool = False


class VisitorDetail(BaseModel):
    date: datetime.date
    visitor_count: int


class BusModel(BaseModel):
    id: int
    total_seats: int


class PassengerModel(BaseModel):
    name: str
    username: str
    gender: str


class AdminModel(BaseModel):
    username: str
    password: str


class MergeModel(BaseModel):
    bus1_id: int
    bus2_id: int
    date: str
