-- 表：Stadium
--  
--  
--  
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | visit_date    | date    |
-- | people        | int     |
-- +---------------+---------+
-- visit_date 是表的主键
-- 每日人流量信息被记录在这三列信息中：序号 (id)、日期 (visit_date)、 人流量 (people)
-- 每天只有一行记录，日期随着 id 的增加而增加
--  
-- 
--  
-- 
--  编写一个 SQL 查询以找出每行的人数大于或等于 100 且 id 连续的三行或更多行记录。 
-- 
--  返回按 visit_date 升序排列的结果表。 
-- 
--  查询结果格式如下所示。 
-- 
--  
-- Stadium table:
-- +------+------------+-----------+
-- | id   | visit_date | people    |
-- +------+------------+-----------+
-- | 1    | 2017-01-01 | 10        |
-- | 2    | 2017-01-02 | 109       |
-- | 3    | 2017-01-03 | 150       |
-- | 4    | 2017-01-04 | 99        |
-- | 5    | 2017-01-05 | 145       |
-- | 6    | 2017-01-06 | 1455      |
-- | 7    | 2017-01-07 | 199       |
-- | 8    | 2017-01-09 | 188       |
-- +------+------------+-----------+
-- 
-- Result table:
-- +------+------------+-----------+
-- | id   | visit_date | people    |
-- +------+------------+-----------+
-- | 5    | 2017-01-05 | 145       |
-- | 6    | 2017-01-06 | 1455      |
-- | 7    | 2017-01-07 | 199       |
-- | 8    | 2017-01-09 | 188       |
-- +------+------------+-----------+
-- id 为 5、6、7、8 的四行 id 连续，并且每行都有 >= 100 的人数记录。
-- 请注意，即使第 7 行和第 8 行的 visit_date 不是连续的，输出也应当包含第 8 行，因为我们只需要考虑 id 连续的记录。
-- 不输出 id 为 2 和 3 的行，因为至少需要三条 id 连续的记录。
--  
--  
--  
--  👍 160 👎 0

# 适合大数据情况下的解法
SELECT p.id, p.visit_date, p.people
FROM (
 SELECT t.id, t.visit_date, t.people, COUNT(*) over(partition by t.id_group) 'continious_ids'
 FROM (
     # 先取大于等于100的记录，在窗口计算下，连续的记录 id - ROW_NUMBER 的值一定相同
     SELECT *, id - row_number() over(order by id) 'id_group' FROM Stadium WHERE people >= 100
 ) t
) p
# 分组求和之后过滤 >= 3 的，则剩下的记录一定是连续超过3条的
WHERE continious_ids >= 3
ORDER BY p.visit_date
;

# 另一种写法
with t1 as (
    select
        id,
        visit_date,
        people,
        # 求出差值，因为id一定不会相同，所以使用最熟悉的rank就好
        id-rank() over(order by id) rk
    from stadium
    where people >= 100
)
select
    id,
    visit_date,
    people
from t1
#where条件过滤出条数大于3的
where rk in (select rk from t1 group by rk having count(1) >= 3);
