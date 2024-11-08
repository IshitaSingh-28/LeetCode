# Write your MySQL query statement below
SELECT product_name, s.year, s.price
from Sales s
JOIN Product p
ON p.product_id=s.product_id