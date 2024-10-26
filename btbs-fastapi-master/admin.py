import asyncio

from db_connection import execute_query, fetch_query, fetch_query_one, transaction, commit, rollback
from bus import Bus
from models.models import AdminModel
from entity import Entity


class Admin:
    @staticmethod
    def add(username, password):
        admin = AdminModel(username=username, password=password)
        return Entity('admin').save(admin)

    @staticmethod
    def authenticate(username, password):
        return Entity('admin').get_where(f"username = '{username}' AND password = '{password}'") != []

    @staticmethod
    def set_merge_status(bus_id, date):
        query = f"INSERT INTO mergestatus (bus_id, date) VALUES ({bus_id}, '{date}')"
        return execute_query(query)

    @staticmethod
    def get_merge_status(bus_id, date):
        query = f"SELECT * FROM mergestatus WHERE bus_id = {bus_id} AND date = '{date}'"
        return fetch_query_one(query) is not None

    @staticmethod
    def reset_merge_status(bus_id, date):
        query = f"DELETE FROM mergestatus WHERE bus_id = {bus_id} AND date = '{date}'"
        return execute_query(query)

    @staticmethod
    def can_merge(bus1_id, bus2_id, date):
        if not Bus.get_by_id(bus1_id) or not Bus.get_by_id(bus2_id):
            return {"error": "Bus not found"}

        if not Bus.get_load_factor(bus1_id, date) <= 0.2 or not Bus.get_load_factor(bus2_id, date) <= 0.2:
            return {"error": "Load factor of both buses should be equal to or below 0.2"}

        bus1 = Bus.get_booked_seats(bus1_id, date)
        bus2 = Bus.get_booked_seats(bus2_id, date)

        if len(bus1 + bus2) != len(set(bus1 + bus2)):
            return {"error": "Seats colliding"}

        return True

    @staticmethod
    def merge_candidates(date):
        buses = Bus.get_all_by_date_booked(date)
        candidates = []
        for i in range(len(buses)):
            for j in range(i + 1, len(buses)):
                if Admin.can_merge(buses[i][0], buses[j][0], date) is True:
                    candidates.append((buses[i][0], buses[j][0]))
        return candidates

    @staticmethod
    async def merge_buses(date, bus1_id, bus2_id):
        await asyncio.sleep(5)
        can_merge_ = Admin.can_merge(bus1_id, bus2_id, date)
        if can_merge_ is not True:
            return can_merge_

        transaction()
        try:
            query = f"""
                    UPDATE seat SET
                    is_booked = TRUE
                    WHERE bus_id = {bus1_id} AND date = '{date}'
                    AND id in
                    (SELECT id FROM (SELECT * FROM seat WHERE bus_id = {bus2_id} AND date = '{date}' AND is_booked = TRUE) as s);
                    """
            execute_query(query)

            query = f"""
                    UPDATE seat SET
                    is_booked = FALSE
                    WHERE bus_id = {bus2_id} AND date = '{date}';
                    """
            execute_query(query)

            query = f"""
                    UPDATE ticket SET
                    bus_id = {bus1_id} WHERE
                    date = '{date}' AND bus_id = {bus2_id};
                    """
            execute_query(query)
            commit()
            return {"success": "Buses are now merged. Bus id: {0}".format(bus1_id)}
        except Exception as e:
            rollback()
            return {"error": str(e)}
