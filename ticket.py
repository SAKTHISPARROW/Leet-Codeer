import asyncio

from db_connection import *
from seat import Seat
import bus
from bus import Bus
from passenger import Passenger
from models.models import TicketModel


class Ticket:
    @staticmethod
    def map_ticket(ticket):
        return {
            "id": ticket[0],
            "passenger_id": ticket[1],
            "bus_id": ticket[2],
            "seat_id": ticket[3],
            "date": ticket[4]
        }

    @staticmethod
    def get_all():
        query = f"SELECT * FROM ticket"
        return fetch_query(query)

    @staticmethod
    def get_by_id(id_):
        query = f"SELECT * FROM ticket WHERE id = {id_}"
        return fetch_query_one(query)

    @staticmethod
    def get_ticket_id(bus_id, seat_id, date):
        query = f"SELECT id FROM ticket WHERE bus_id = {bus_id} AND seat_id = {seat_id} AND date = '{date}'"
        return fetch_query_one(query)

    @staticmethod
    def get_user_tickets(username):
        query = f"SELECT * FROM ticket WHERE passenger_id in (SELECT passenger_id FROM passenger WHERE username = '{username}') ORDER BY date DESC"
        return fetch_query(query)

    @staticmethod
    def insert_ticket(bus_id, seat_id, passenger_id, date):
        query = f"INSERT INTO ticket (bus_id, seat_id, passenger_id, date) VALUES ({bus_id}, {seat_id}, {passenger_id}, '{date}')"
        return execute_query(query)

    @staticmethod
    def delete_ticket(id_):
        query = f"DELETE FROM ticket WHERE id = {id_}"
        return execute_query(query)

    @staticmethod
    def is_already_booked(bus_id, seat_id, date):
        query = f"SELECT * FROM ticket WHERE bus_id = {bus_id} AND seat_id = {seat_id} AND date = '{date}'"
        return fetch_query_one(query) is not None

    @staticmethod
    def book_ticket(bus_id, seat_id, passenger_id, date):
        if not Passenger.get_by_id(passenger_id):
            return {"error": "Passenger not found"}

        if Bus.get_by_id(bus_id) is None:
            return {"error": "Bus not found"}

        if Ticket.is_already_booked(bus_id, seat_id, date):
            return {"error": "Seat is already booked"}

        try:
            if Seat.book_seat(seat_id, bus_id, date) is not True:
                return {"error": "Seat booking failed"}
            if Ticket.insert_ticket(bus_id, seat_id, passenger_id, date):
                ticket_id = Ticket.get_ticket_id(bus_id, seat_id, date)
                id_ = Bus.is_load_factor_maxed(date)
                if id_:
                    for i in range(1, bus.BUS_ADDITION_FACTOR + 1):
                        print(Bus.add_for_date((id_ + i), date))
                return {"success": "Ticket booked successfully. Ticket ID: " + str(ticket_id[0])}
            else:
                return {"error": "Ticket booking failed"}
        except Exception as e:
            return {"error": str(e)}

    @staticmethod
    def cancel_ticket(id_):
        ticket = Ticket.get_by_id(id_)
        if not ticket:
            return {"error": "Ticket not found"}

        try:
            ticket_map = Ticket.map_ticket(ticket)
            if Seat.cancel_seat(ticket_map["seat_id"], ticket_map["bus_id"], ticket_map["date"]) is not True:
                return {"error": "Seat cancellation failed"}
            if Ticket.delete_ticket(id_):
                return {"success": "Ticket cancelled successfully"}
            else:
                return {"error": "Ticket cancellation failed"}
        except Exception as e:
            return {"error": str(e)}

    @staticmethod
    async def payment(tickets: list[TicketModel]):
        ticket = tickets[0]
        seat_ids = [ticket.seat_id for ticket in tickets]
        if Seat.is_being_booked(seat_ids, ticket.bus_id, ticket.date):
            if not ticket.lock:
                return {"error": "Being booked by other user"}
        Seat.set_is_being_booked(seat_ids, ticket.bus_id, ticket.date)
        try:
            await asyncio.wait_for(asyncio.sleep(0), timeout=15)
            print("Payment successful")
            booking_response = []
            for ticket in tickets:
                booking_response.append(Ticket.book_ticket(ticket.bus_id, ticket.seat_id, ticket.passenger_id, ticket.date))
            return booking_response
        except asyncio.TimeoutError:
            print("Payment failed")
            return {"error": "Payment timed out"}
        finally:
            Seat.reset_is_being_booked(seat_ids, ticket.bus_id, ticket.date)
