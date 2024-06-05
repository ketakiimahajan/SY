SELECT * FROM customer

SELECT customer_name, customer_mobile, customer_email
FROM customer
WHERE customer_address = 'Mumbai'
UNION
SELECT customer_name, customer_mobile, customer_email
FROM customer
WHERE pay_amount > 5000;

SELECT customer_name, customer_mobile, customer_email
FROM customer
WHERE customer_address = 'Mumbai'
INTERSECT
SELECT customer_name, customer_mobile, customer_email
FROM customer
WHERE pay_amount > 5000;

SELECT customer_address, SUM(pay_amount)
FROM customer
GROUP BY customer_address;

SELECT *
FROM customer
WHERE pay_amount > ANY (SELECT AVG(booking_id) FROM customer);

SELECT customer_name, customer_mobile, customer_address, customer_email
FROM customer
WHERE customer_address = 'Mumbai'
AND pay_amount > 0
EXCEPT
SELECT customer_name, customer_mobile, customer_address, customer_email
FROM customer
WHERE customer_address = 'Mumbai'
AND booking_id IS NOT NULL;

SELECT *
FROM customer
WHERE pay_amount > ALL (SELECT MAX(pay_amount) FROM customer WHERE customer_address = 'Indore');

SELECT COUNT(*)
FROM customer;

SELECT MAX(pay_amount) AS Maximum_Pay_Amount from customer;

SELECT MIN(pay_amount) AS Minimum_Pay_Amount from customer;

SELECT SUM(pay_amount) AS Total_Pay_Amount from customer;

SELECT customer_name
FROM customer
GROUP BY customer_name, customer_address
HAVING AVG(pay_amount) >= ALL (
    SELECT AVG(pay_amount)
    FROM customer
    GROUP BY customer_address
);

SELECT *
FROM customer
ORDER BY room_no ASC;

SELECT *
FROM customer
ORDER BY customer_address ASC, pay_amount DESC;

SELECT *,
       pay_amount * 0.95 AS discounted_total_payment
FROM customer
ORDER BY discounted_total_payment DESC;

SELECT *
FROM customer
ORDER BY 2 ASC;

SELECT *
FROM customer
WHERE customer_id NOT BETWEEN 1 AND 90;

SELECT * FROM customer WHERE customer_address NOT IN('Mumbai', 'Delhi', 'Kolkata', 'Chennai');

SELECT *
FROM customer
WHERE customer_name LIKE 'A%';

SELECT *
FROM customer
ORDER BY (CASE customer_address
            WHEN 'Mumbai' THEN 1
            WHEN 'Delhi' THEN 2
            WHEN 'Pune' THEN 3
            WHEN 'Lucknow' THEN 4
            WHEN 'Indore' THEN 5
            ELSE 100
         END) ASC, customer_address DESC;

