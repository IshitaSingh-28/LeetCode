# Write your MySQL query statement below
SELECT contest_id ,
round(count(distinct user_id)*100/(select count(user_id)from users),2) as percentage
FROM Register 
Group by contest_id
Order by percentage desc ,contest_id asc

