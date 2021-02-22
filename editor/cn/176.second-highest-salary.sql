-- 编写一个 SQL 查询，获取 Employee 表中第二高的薪水（Salary） 。 
-- 
--  +----+--------+
-- | Id | Salary |
-- +----+--------+
-- | 1  | 100    |
-- | 2  | 200    |
-- | 3  | 300    |
-- +----+--------+
--  
-- 
--  例如上述 Employee 表，SQL查询应该返回 200 作为第二高的薪水。如果不存在第二高的薪水，那么查询应返回 null。 
-- 
--  +---------------------+
-- | SecondHighestSalary |
-- +---------------------+
-- | 200                 |
-- +---------------------+
--  
--  👍 721 👎 0

# 需要用 IFNULL 包起来
SELECT IFNULL((
  SELECT
      DISTINCT Salary
  FROM (
      SELECT
          Salary, DENSE_RANK() OVER(ORDER BY Salary DESC) AS "Nth"
      FROM
          Employee
   ) A
  WHERE Nth=2)
, NULL) AS 'SecondHighestSalary'