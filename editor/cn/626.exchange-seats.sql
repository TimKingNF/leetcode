-- 小美是一所中学的信息科技老师，她有一张 seat 座位表，平时用来储存学生名字和与他们相对应的座位 id。 
-- 
--  其中纵列的 id 是连续递增的 
-- 
--  小美想改变相邻俩学生的座位。 
-- 
--  你能不能帮她写一个 SQL query 来输出小美想要的结果呢？ 
-- 
--  
-- 
--  示例： 
-- 
--  
-- +---------+---------+
-- |    id   | student |
-- +---------+---------+
-- |    1    | Abbot   |
-- |    2    | Doris   |
-- |    3    | Emerson |
-- |    4    | Green   |
-- |    5    | Jeames  |
-- +---------+---------+
--  
-- 
--  假如数据输入的是上表，则输出结果如下： 
-- 
--  
-- +---------+---------+
-- |    id   | student |
-- +---------+---------+
-- |    1    | Doris   |
-- |    2    | Abbot   |
-- |    3    | Green   |
-- |    4    | Emerson |
-- |    5    | Jeames  |
-- +---------+---------+ 
-- 
--  注意： 
-- 
--  如果学生人数是奇数，则不需要改变最后一个同学的座位。 
--  👍 220 👎 0

# 解法一
# 先计算出所有座位的数量
SELECT
    (CASE
         /* 其他奇数座位改为 id+1 */
         WHEN MOD(id, 2) != 0 AND counts != id THEN id + 1
         /* 如果 id 刚好是 counts 且是奇数，则 id 不用修改 */
         WHEN MOD(id, 2) != 0 AND counts = id THEN id
         /* 剩下偶数座位改为 id-1 */
         ELSE id - 1
        END) AS id,
    student
FROM
    seat,
    /* 查询座位数量 */
    (SELECT
         COUNT(*) AS counts
     FROM
         seat) AS seat_counts
ORDER BY id ASC
;


# 解法二
# 利用异或只把偶数减2，奇数不变，从而调位。（单数-1后，最后一位是0，异或把最后一位变回1，等于不变；偶数-1后，最后一位是1，异或把最后一位变成0，等于再减去1）
# 这样将原来 偶数id 移动到奇数前 如 2 放到 1前， 4放到3前，然后 row_number 重新排号
select row_number() over(order by (id-1)^1) as id,student from seat;