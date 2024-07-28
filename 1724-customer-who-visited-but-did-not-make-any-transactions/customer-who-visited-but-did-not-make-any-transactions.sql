# Write your MySQL query statement below
-- SELECT *
SELECT customer_id, sum(if(Transactions.visit_id is null, 1, 0)) as count_no_trans
FROM Visits LEFT JOIN Transactions on Visits.visit_id = Transactions.visit_id
GROUP BY customer_id having count_no_trans > 0