# Write your MySQL query statement below
SELECT
EU.unique_id, E.name
FROM Employees E
LEFT JOIN EmployeeUNI EU on E.id = EU.id