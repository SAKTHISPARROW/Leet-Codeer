from db_connection import execute_query, fetch_query, fetch_query_one
from pydantic import BaseModel


class Entity:
    def __init__(self, table: str):
        self.table = table

    def save(self, model: BaseModel):
        columns = model.__dict__.keys()
        values = model.__dict__.values()
        columns_ = ', '.join(columns)
        values_ = ', '.join([f"'{x}'" if isinstance(x, str) else 'NULL' if x is None else str(x) for x in values])
        query = f"INSERT INTO {self.table} ({columns_}) VALUES ({values_})"
        return execute_query(query)

    def delete_by_id(self, id_column, id_value):
        query = f"DELETE FROM {self.table} WHERE {id_column} = {id_value}"
        return execute_query(query)

    def delete_where(self, condition):
        query = f"DELETE FROM {self.table} WHERE {condition}"
        return execute_query(query)

    def get_all(self):
        query = f"SELECT * FROM {self.table}"
        return fetch_query(query)

    def get_by_id(self, id_column, id_value):
        query = f"SELECT * FROM {self.table} WHERE {id_column} = {id_value}"
        return fetch_query_one(query)

    def get_where(self, condition):
        query = f"SELECT * FROM {self.table} WHERE {condition}"
        return fetch_query(query)

    def get_columns_where(self, columns, condition):
        query = f"SELECT {columns} FROM {self.table} WHERE {condition}"
        return fetch_query(query)

    def get_column_where(self, column, condition):
        query = f"SELECT {column} FROM {self.table} WHERE {condition}"
        return fetch_query_one(query)

    def update_where(self, updates, condition):
        query = f"UPDATE {self.table} SET {updates} WHERE {condition}"
        return execute_query(query)
