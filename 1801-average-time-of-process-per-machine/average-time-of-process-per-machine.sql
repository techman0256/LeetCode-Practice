# Write your MySQL query statement below
select t1.machine_id, round(avg(t1.diff),3) as processing_time
from (
    SELECT X.machine_id, X.process_id, (Y.timestamp - X.timestamp) as diff
    FROM Activity as X inner join Activity as Y on (X.machine_id, X.process_id) = (Y.machine_id, Y.process_id)
    where X.activity_type = 'start' and Y.activity_type = 'end'
) as t1
group by machine_id




-- SELECT machine_id, process_id, ()
-- from activity

-- select process_id, 
-- from activity as t


-- group by machine_id, process_id
