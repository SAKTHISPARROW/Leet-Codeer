from pydantic import BaseModel
from entity import Entity


class UserModel(BaseModel):
    """
    User Model
    """
    username: str
    password: str


class User:
    """
    User Class
    """
    @staticmethod
    def add(username, password):
        user = UserModel(username=username, password=password)
        return Entity('user').save(user)

    @staticmethod
    def authenticate(username, password):
        return Entity('user').get_where(f"username = '{username}' AND password = '{password}'") != []
