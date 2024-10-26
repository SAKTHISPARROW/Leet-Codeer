import mysql.connector
from dotenv import dotenv_values

env_values = dotenv_values(".env")


config = {
    "user": env_values["DB_USER"],
    "password": env_values["DB_PASS"],
    "host": env_values["DB_HOST"],
    "database": env_values["DB_NAME"]
}

connection_pool = mysql.connector.pooling.MySQLConnectionPool(
    pool_name="btbs_pool",
    pool_size=32,
    **config,
    autocommit=True
)


def transaction():
    return connection_pool.get_connection().start_transaction()


def commit():
    return connection_pool.get_connection().commit()


def rollback():
    return connection_pool.get_connection().rollback()


'''
def execute_atomic(queries):
    get_connection().start_transaction()
    try:
        for query in queries:
            execute_query(query)
        get_connection().commit()
    except Exception as e:
        get_connection().rollback()
        return e
'''

# Generic methods for CRUD operations


def execute_query(query):
    try:
        conn = connection_pool.get_connection()
        cursor = conn.cursor(buffered=True)
        cursor.execute(query)
        conn.close()
    except Exception as e:
        print(e)
        raise e
    return True


def fetch_query(query):
    try:
        conn = connection_pool.get_connection()
        cursor = conn.cursor(buffered=True)
        cursor.execute(query)
        res = cursor.fetchall()
        conn.close()
        return res
    except Exception as e:
        print(e)
        raise e


def fetch_query_one(query):
    try:
        conn = connection_pool.get_connection()
        cursor = conn.cursor(buffered=True)
        cursor.execute(query)
        res = cursor.fetchone()
        conn.close()
        return res
    except Exception as e:
        print(e)
        raise e
