# Write your MySQL query statement below

SELECT e.name,eu.unique_id
FROM 
Employees as e
LEFT JOIN
EmployeeUNI as eu
ON
e.id=eu.id;