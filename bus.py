from seat import Seat
from db_connection import execute_query, fetch_query, fetch_query_one
from entity import Entity
from models.models import BusModel


class Bus:
    MAX_BUS = 10
    INITIAL_BUS = 4
    BUS_ADDITION_FACTOR = 1

    @staticmethod
    def add(id_, total_seats):
        if len(Bus.get_all()) >= Bus.MAX_BUS:
            return {"error": "Maximum bus limit reached"}
        bus = BusModel(id=id_, total_seats=total_seats)
        return Entity('bus').save(bus)

    @staticmethod
    def add_for_date(id_, date):
        if (len(Bus.get_all_by_date(date))) >= Bus.MAX_BUS:
            return {"error": "Maximum bus limit reached"}
        Seat.initialize_seats(id_, date)
        return {"success": f"Bus {id_} added for {date}"}

    @staticmethod
    def delete_by_id(id_):
        if len(Bus.get_all()) < Bus.INITIAL_BUS:
            return {"error": "Minimum bus limit reached"}
        return Entity('bus').delete_by_id('id', id_)

    @staticmethod
    def delete_for_date(id_, date):
        if not Bus.get_by_date(id_, date):
            return {"error": "Bus not found"}
        query = f"DELETE FROM seat where bus_id = {id_} AND date = '{date}'"
        return execute_query(query)

    @staticmethod
    def get_by_id(id_):
        return Entity('bus').get_by_id('id', id_)

    @staticmethod
    def get_all():
        return Entity('bus').get_all()

    @staticmethod
    def get_by_date(id_, date):
        query = f"SELECT * FROM seat WHERE bus_id = {id_} AND date = '{date}'"
        return fetch_query(query)

    @staticmethod
    def get_all_by_date(date):
        query = f"SELECT DISTINCT bus_id FROM seat WHERE date = '{date}'"
        return fetch_query(query)

    @staticmethod
    def get_all_by_date_booked(date):
        query = f"SELECT DISTINCT bus_id FROM seat WHERE date = '{date}' AND is_booked = TRUE"
        return fetch_query(query)

    @staticmethod
    def get_total_seats(bus_id):
        return Entity('bus').get_column_where('total_seats', f'id = {bus_id}')

    @staticmethod
    def get_available_seats(bus_id_, date):
        query = f"SELECT id FROM seat WHERE bus_id = {bus_id_} AND date = '{date}' AND is_booked=FALSE"
        return fetch_query(query)

    @staticmethod
    def get_booked_seats(bus_id_, date):
        query = f"SELECT id from seat WHERE bus_id = {bus_id_} AND date = '{date}' AND is_booked = TRUE"
        return fetch_query(query)

    @staticmethod
    def get_load_factor(bus_id_, date):
        load_factor = len(Bus.get_booked_seats(bus_id_, date)) / Bus.get_total_seats(bus_id_)[0]
        return load_factor

    @staticmethod
    def is_load_factor_maxed(date):
        buses = Bus.get_all_by_date(date)
        ids = [id_[0] for id_ in buses]
        if not ids:
            return False
        for id_ in ids:
            if Bus.get_load_factor(id_, date) < 0.8:
                return False
        return ids[-1]
