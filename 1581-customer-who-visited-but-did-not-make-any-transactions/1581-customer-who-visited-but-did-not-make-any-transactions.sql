# Write your MySQL query statement below
SELECT v.customer_id ,count(v.visit_id) as count_no_trans
FROM Visits v
LEFT JOIN Transactions t 
on t.visit_id = v.visit_id
where transaction_id IS NULL
group by customer_id

