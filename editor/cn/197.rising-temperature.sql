-- 
--  
--  表 Weather 
-- 
--  
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | recordDate    | date    |
-- | temperature   | int     |
-- +---------------+---------+
-- id 是这个表的主键
-- 该表包含特定日期的温度信息 
-- 
--  
-- 
--  编写一个 SQL 查询，来查找与之前（昨天的）日期相比温度更高的所有日期的 id 。 
-- 
--  返回结果 不要求顺序 。 
-- 
--  查询结果格式如下例： 
-- 
--  
-- Weather
-- +----+------------+-------------+
-- | id | recordDate | Temperature |
-- +----+------------+-------------+
-- | 1  | 2015-01-01 | 10          |
-- | 2  | 2015-01-02 | 25          |
-- | 3  | 2015-01-03 | 20          |
-- | 4  | 2015-01-04 | 30          |
-- +----+------------+-------------+
-- 
-- Result table:
-- +----+
-- | id |
-- +----+
-- | 2  |
-- | 4  |
-- +----+
-- 2015-01-02 的温度比前一天高（10 -> 25）
-- 2015-01-04 的温度比前一天高（20 -> 30）
--  
--  
--  
--  👍 187 👎 0

# 解法一
# 利用 DATEDIFF 比较两个日期差值为 1
SELECT
    Weather.id
FROM
    Weather
        JOIN
    Weather w ON DATEDIFF(Weather.recordDate, w.recordDate) = 1
        AND Weather.temperature > w.temperature
;

# 解法二
# 速度更快些
SELECT
    A.id
FROM
    Weather A JOIN Weather B
ON (A.recordDate = DATE_ADD(B.recordDate, INTERVAL 1 DAY))
WHERE
    A.temperature > B.temperature
;