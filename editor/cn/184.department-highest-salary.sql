-- Employee 表包含所有员工信息，每个员工有其对应的 Id, salary 和 department Id。 
-- 
--  +----+-------+--------+--------------+
-- | Id | Name  | Salary | DepartmentId |
-- +----+-------+--------+--------------+
-- | 1  | Joe   | 70000  | 1            |
-- | 2  | Jim   | 90000  | 1            |
-- | 3  | Henry | 80000  | 2            |
-- | 4  | Sam   | 60000  | 2            |
-- | 5  | Max   | 90000  | 1            |
-- +----+-------+--------+--------------+ 
-- 
--  Department 表包含公司所有部门的信息。 
-- 
--  +----+----------+
-- | Id | Name     |
-- +----+----------+
-- | 1  | IT       |
-- | 2  | Sales    |
-- +----+----------+ 
-- 
--  编写一个 SQL 查询，找出每个部门工资最高的员工。对于上述表，您的 SQL 查询应返回以下行（行的顺序无关紧要）。 
-- 
--  +------------+----------+--------+
-- | Department | Employee | Salary |
-- +------------+----------+--------+
-- | IT         | Max      | 90000  |
-- | IT         | Jim      | 90000  |
-- | Sales      | Henry    | 80000  |
-- +------------+----------+--------+ 
-- 
--  解释： 
-- 
--  Max 和 Jim 在 IT 部门的工资都是最高的，Henry 在销售部的工资最高。 
--  👍 337 👎 0

# 解法一
SELECT
    D.Name AS 'Department', C.Name AS 'Employee', C.Salary
FROM (
    SELECT
        A.*
    FROM
        Employee A RIGHT JOIN (
            SELECT
                DepartmentId, MAX(Salary) AS 'MaxSalary'
            FROM
                Employee
            GROUP BY DepartmentId
        ) B
    ON A.DepartmentId=B.DepartmentId
    WHERE A.Salary=B.MaxSalary) C,
    Department D
WHERE
    C.DepartmentId=D.Id
;

# 在解法一的基础上再简化一下，主要是简化掉 取所有Slary等于MaxSalary这一步
# 少了一层嵌套循环
SELECT
    Department.name AS 'Department',
    Employee.name AS 'Employee',
    Salary
FROM
    Employee
        JOIN
    Department ON Employee.DepartmentId = Department.Id
WHERE
    (Employee.DepartmentId , Salary) IN
    (   SELECT
            DepartmentId, MAX(Salary)
        FROM
            Employee
        GROUP BY DepartmentId
    )
;
