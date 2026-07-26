SELECT
    Department.name AS Department,
    t.name AS Employee,
    t.salary AS Salary
FROM (
    SELECT *,
           DENSE_RANK() OVER (
               PARTITION BY departmentId
               ORDER BY salary DESC
           ) AS rnk
    FROM Employee
) t
JOIN Department
ON Department.id = t.departmentId
WHERE rnk <= 3;