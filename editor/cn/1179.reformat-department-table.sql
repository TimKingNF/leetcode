-- 部门表 Department： 
-- 
--  
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | revenue       | int     |
-- | month         | varchar |
-- +---------------+---------+
-- (id, month) 是表的联合主键。
-- 这个表格有关于每个部门每月收入的信息。
-- 月份（month）可以取下列值 ["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","
-- Nov","Dec"]。
--  
-- 
--  
-- 
--  编写一个 SQL 查询来重新格式化表，使得新的表中有一个部门 id 列和一些对应 每个月 的收入（revenue）列。 
-- 
--  查询结果格式如下面的示例所示： 
-- 
--  
-- Department 表：
-- +------+---------+-------+
-- | id   | revenue | month |
-- +------+---------+-------+
-- | 1    | 8000    | Jan   |
-- | 2    | 9000    | Jan   |
-- | 3    | 10000   | Feb   |
-- | 1    | 7000    | Feb   |
-- | 1    | 6000    | Mar   |
-- +------+---------+-------+
-- 
-- 查询得到的结果表：
-- +------+-------------+-------------+-------------+-----+-------------+
-- | id   | Jan_Revenue | Feb_Revenue | Mar_Revenue | ... | Dec_Revenue |
-- +------+-------------+-------------+-------------+-----+-------------+
-- | 1    | 8000        | 7000        | 6000        | ... | null        |
-- | 2    | 9000        | null        | null        | ... | null        |
-- | 3    | null        | 10000       | null        | ... | null        |
-- +------+-------------+-------------+-------------+-----+-------------+
-- 
-- 注意，结果表有 13 列 (1个部门 id 列 + 12个月份的收入列)。
--  
--  👍 94 👎 0

SELECT id,
   SUM(CASE WHEN month='Jan' THEN revenue END) AS Jan_Revenue,
   SUM(CASE WHEN month='Feb' THEN revenue END) AS Feb_Revenue,
   SUM(CASE WHEN month='Mar' THEN revenue END) AS Mar_Revenue,
   SUM(CASE WHEN month='Apr' THEN revenue END) AS Apr_Revenue,
   SUM(CASE WHEN month='May' THEN revenue END) AS May_Revenue,
   SUM(CASE WHEN month='Jun' THEN revenue END) AS Jun_Revenue,
   SUM(CASE WHEN month='Jul' THEN revenue END) AS Jul_Revenue,
   SUM(CASE WHEN month='Aug' THEN revenue END) AS Aug_Revenue,
   SUM(CASE WHEN month='Sep' THEN revenue END) AS Sep_Revenue,
   SUM(CASE WHEN month='Oct' THEN revenue END) AS Oct_Revenue,
   SUM(CASE WHEN month='Nov' THEN revenue END) AS Nov_Revenue,
   SUM(CASE WHEN month='Dec' THEN revenue END) AS Dec_Revenue
FROM department
GROUP BY id
ORDER BY id;