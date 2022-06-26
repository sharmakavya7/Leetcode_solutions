-- # Please write a DELETE statement and DO NOT write a SELECT statement.
-- Write an SQL query to delete all the duplicate emails, keeping only one unique email with the smallest id
-- # Write your MySQL query statement below
DELETE p1
FROM Person p1, Person p2
WHERE p1.email = p2.email AND
p1.id > p2.id


-- # Write your MySQL query statement below
-- Write an SQL query to report all the duplicate emails.
-- Return the result table in any order.

SELECT email FROM Person
GROUP BY email 
HAVING COUNT(id) > 1;