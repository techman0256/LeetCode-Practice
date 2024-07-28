# Write your MySQL query statement below
SELECT W.id as Id
FROM Weather as W JOIN Weather as T WHERE W.recordDate = DATE_ADD(T.recordDate, INTERVAL 1 DAY) and W.temperature > T.temperature
ORDER BY W.recordDate