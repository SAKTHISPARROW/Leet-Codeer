CREATE DATABASE btbs;
USE btbs;

CREATE TABLE passenger (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255),
    gender ENUM('M', 'F', 'T', 'U') DEFAULT 'U',
    username VARCHAR(255),
    FOREIGN KEY (username) REFERENCES user(username)
);

CREATE TABLE bus (
    id INT PRIMARY KEY,
    total_seats INT
);

CREATE TABLE seat (
    id INT,
    bus_id INT,
    date DATE,
    is_booked BOOLEAN DEFAULT FALSE,
    is_being_booked BOOLEAN DEFAULT FALSE,
    PRIMARY KEY (id, bus_id, date),
    FOREIGN KEY (bus_id) REFERENCES bus(id)
);

CREATE TABLE ticket (
    id INT PRIMARY KEY AUTO_INCREMENT,
    passenger_id INT,
    bus_id INT,
    seat_id INT,
    date DATE,
    FOREIGN KEY (passenger_id) REFERENCES passenger(id),
    FOREIGN KEY (bus_id) REFERENCES bus(id),
    FOREIGN KEY (seat_id) REFERENCES seat(id)
);

CREATE TABLE user (
    username VARCHAR(255) PRIMARY KEY,
    password VARCHAR(255)
);

CREATE TABLE admin (
    username VARCHAR(255) PRIMARY KEY,
    password VARCHAR(255)
);

CREATE TABLE log (
    ip VARCHAR(255),
    time TIMESTAMP
);


CREATE TABLE mergestatus (
    bus_id INT,
    date DATE,
    PRIMARY KEY (bus_id, date)
);
