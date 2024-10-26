from db_connection import execute_query, fetch_query, fetch_query_one


def insert_log(ip, time):
    query = f"INSERT INTO log (ip, time) VALUES ('{ip}', '{time}')"
    return execute_query(query)


def get_all():
    query = f"SELECT * FROM log"
    return fetch_query(query)


def get_by_dates():
    query = f"SELECT DATE(time), COUNT(DISTINCT ip) FROM log GROUP BY DATE(time) ORDER BY DATE(time) DESC"
    return fetch_query(query)


def get_by_date(date):
    query = f"SELECT COUNT(DISTINCT ip) FROM log WHERE DATE(time) = '{date}'"
    return fetch_query_one(query)
