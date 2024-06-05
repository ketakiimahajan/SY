SELECT * FROM customer

SELECT customer_name, customer_mobile, customer_email, customer_address FROM customer

SELECT * FROM customer WHERE customer_address = 'Mumbai';

SELECT * FROM customer WHERE customer_address = 'Mumbai' AND pay_amount > 5000;

SELECT * FROM customer WHERE room_no BETWEEN 10 AND 200;

SELECT * FROM customer WHERE customer_address IN('Patna', 'Delhi');

SELECT * FROM customer WHERE customer_address NOT IN('Patna', 'Delhi');

ALTER TABLE customer 
ADD COLUMN booking_date DATE;

ALTER TABLE customer 
DROP COLUMN booking_date;

SELECT * FROM customer ORDER BY customer_name ASC;