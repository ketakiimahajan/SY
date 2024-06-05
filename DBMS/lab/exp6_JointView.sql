-- Cross Join
SELECT *
FROM Customer
CROSS JOIN Rooms;

-- Inner Join
SELECT Customer.customer_name, Customer.customer_phone, Booking.check_in_date
FROM Booking
INNER JOIN Customer ON Booking.customer_id = Customer.customer_id;

-- Left Outer Join
SELECT Customer.customer_id, Customer.customer_name, Customer.customer_phone
FROM Customer
LEFT OUTER JOIN Customer_Services ON Customer.customer_id = Customer_Services.customer_id
WHERE Customer_Services.service_id = 222;

-- Right Outer Join
SELECT Customer.customer_name, Customer.customer_phone, Customer.customer_email
FROM Customer
RIGHT OUTER JOIN Booking ON Customer.customer_id = Booking.customer_id
WHERE Booking.check_in_date > '2024-01-01';

-- Full Outer Join
SELECT *
FROM Customer
FULL OUTER JOIN Booking ON Customer.customer_id = Booking.customer_id;

DROP VIEW IF EXISTS Booking_Details;

-- Creating View
CREATE VIEW Booking_Details AS
SELECT b.booking_id, c.customer_name, c.customer_email, c.customer_phone, 
       r.room_number, r.room_type, r.room_price, 
       b.check_in_date, b.check_out_date, b.booking_date
FROM Booking b
INNER JOIN Customer c ON b.customer_id = c.customer_id
INNER JOIN Rooms r ON b.room_id = r.room_id;

SELECT * FROM Booking_Details;

-- POST LAB QUESTIONS

CREATE TABLE class (
    id INT PRIMARY KEY,
    name VARCHAR(100)
);

INSERT INTO class (id, name)
VALUES
(1, 'abhi'),
(2, 'adam'),
(3, 'alex'),
(4, 'anu'),
(5, 'ashish');

CREATE TABLE class_info (
    id INT PRIMARY KEY,
    address VARCHAR(255)
);

INSERT INTO class_info (id, address)
VALUES
(1, 'delhi'),
(2, 'mumbai'),
(3, 'chennai'),
(7, 'noida'),
(8, 'panipat');

SELECT c.id, c.name, ci.id AS class_info_id, ci.address
FROM class c
FULL OUTER JOIN class_info ci ON c.id = ci.id
ORDER BY c.id;
