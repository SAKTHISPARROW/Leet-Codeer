from models.models import PassengerModel
from entity import Entity
from db_connection import execute_query, fetch_query, fetch_query_one


class Passenger:
    @staticmethod
    def add(name, username, gender):
        passenger = PassengerModel(name=name, username=username, gender=gender)
        return Entity('passenger').save(passenger)

    @staticmethod
    def get_all():
        return fetch_query("SELECT * FROM passenger")

    @staticmethod
    def get_by_id(id_):
        return fetch_query_one(f"SELECT * FROM passenger WHERE id = {id_}")

    @staticmethod
    def get_all_by_username(username):
        return fetch_query(f"SELECT * FROM passenger WHERE username = '{username}'")

    @staticmethod
    def get_all_by_username_for_seats(username, date, bus_id):
        query = f"""
                SELECT * FROM passenger WHERE username = '{username}' 
                AND id not in 
                (SELECT passenger_id FROM ticket WHERE date = '{date}' AND bus_id = {bus_id})
                """
        return fetch_query(query)

    @staticmethod
    def get_username(passenger_id):
        return Entity('passenger').get_column_where('username', f"id = {passenger_id}")[0]

    @staticmethod
    def update_by_id(id_, name):
        query = f"UPDATE passenger SET name = '{name}' WHERE id = {id_}"
        return execute_query(query)

    @staticmethod
    def delete(id_):
        query = f"DELETE FROM passenger WHERE id = {id_}"
        return execute_query(query)

    @staticmethod
    def map_passenger(passenger):
        return {
            "id": passenger[0],
            "name": passenger[1],
            "gender": passenger[2]
        }


# def add(name, username):
#     query = f"INSERT INTO passenger (name, username) VALUES ('{name}', '{username}')"
#     return execute_query(query)


# def get_all():
#     query = "SELECT * FROM passenger"
#     return fetch_query(query)


# def get_by_id(id_):
#     query = f"SELECT * FROM passenger WHERE id = {id_}"
#     return fetch_query_one(query)


# def get_all_by_username(username):
#     query = f"SELECT * FROM passenger WHERE username = '{username}'"
#     return fetch_query(query)


# def update_by_id(id_, name):
#     query = f"UPDATE passenger SET name = '{name}' WHERE id = {id_}"
#     return execute_query(query)


# def delete(id_):
#     query = f"DELETE FROM passenger WHERE id = {id_}"
#     return execute_query(query)
