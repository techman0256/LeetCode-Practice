# Write your MySQL query statement below
SELECT name, bonus
FROM Employee LEFT JOIN Bonus on Employee.empId = Bonus.empId
HAVING bonus < 1000 or Bonus is NULL;