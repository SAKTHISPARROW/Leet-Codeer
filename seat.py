from db_connection import execute_query, fetch_query, fetch_query_one


class Seat:
    @staticmethod
    def get_all():
        query = "SELECT * FROM seat"
        return fetch_query(query)

    @staticmethod
    def get_all_by_bus_id(bus_id):
        query = f"SELECT * FROM seat WHERE bus_id = {bus_id}"
        return fetch_query(query)

    @staticmethod
    def get_all_by_date(bus_id, date):
        query = f"SELECT * FROM seat WHERE bus_id = {bus_id} AND date = '{date}'"
        return fetch_query(query)

    @staticmethod
    def get_by_id(id_, bus_id_, date):
        query = f"SELECT * FROM seat WHERE id = {id_} AND bus_id = {bus_id_} AND date = '{date}'"
        return fetch_query_one(query)

    @staticmethod
    def initialize_seats(bus_id_, date):
        if Seat.get_all_by_date(bus_id_, date):
            return {"error": "Already initialized"}

        total_seats = fetch_query_one(f"SELECT total_seats FROM bus WHERE id = {bus_id_}")[0]
        for i in range(1, total_seats + 1):
            execute_query(f"INSERT INTO seat (id, bus_id, date) VALUES ({i}, {bus_id_}, '{date}')")

    @staticmethod
    def set_is_being_booked(ids, bus_id_, date):
        query = f"UPDATE seat SET is_being_booked = TRUE WHERE id in ({','.join(map(str, ids))}) AND bus_id = {bus_id_} AND date = '{date}'"
        return execute_query(query)

    @staticmethod
    def reset_is_being_booked(ids, bus_id_, date):
        query = f"UPDATE seat SET is_being_booked = FALSE WHERE id in ({','.join(map(str, ids))}) AND bus_id = {bus_id_} AND date = '{date}'"
        return execute_query(query)

    @staticmethod
    def is_being_booked(ids, bus_id_, date):
        query = f"SELECT is_being_booked FROM seat WHERE id in ({','.join(map(str, ids))}) AND bus_id = {bus_id_} AND date = '{date}' AND is_being_booked = TRUE"
        return fetch_query(query) != []

    @staticmethod
    def book_seat(id_, bus_id_, date):
        query = f"UPDATE seat SET is_booked=TRUE WHERE bus_id={bus_id_} AND id={id_} AND date = '{date}'"
        return execute_query(query)

    @staticmethod
    def cancel_seat(id_, bus_id_, date):
        query = f"UPDATE seat SET is_booked=FALSE WHERE id={id_} AND bus_id={bus_id_} AND date = '{date}'"
        return execute_query(query)

