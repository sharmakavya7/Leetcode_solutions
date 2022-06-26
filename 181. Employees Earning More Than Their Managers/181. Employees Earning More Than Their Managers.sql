-- Write an SQL query to find the employees who earn more than their managers.     

-- # Write your MySQL query statement below

SELECT E1.name AS Employee 
FROM Employee AS E1, Employee AS E2 
WHERE E1.managerid = E2.id AND
E1.salary > E2.salary