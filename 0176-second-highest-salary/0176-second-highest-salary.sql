# Write your MySQL query statement below
select max(t1.salary) as SecondHighestSalary
from Employee as t1
where t1.salary !=(select max(t2.salary)
                    from Employee as t2);