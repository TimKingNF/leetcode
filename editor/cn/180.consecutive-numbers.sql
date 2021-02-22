# 表：Logs 
# 
#  
# +-------------+---------+
# | Column Name | Type    |
# +-------------+---------+
# | id          | int     |
# | num         | varchar |
# +-------------+---------+
# id 是这个表的主键。 
# 
#  
# 
#  编写一个 SQL 查询，查找所有至少连续出现三次的数字。 
# 
#  返回的结果表中的数据可以按 任意顺序 排列。 
# 
#  
# 
#  查询结果格式如下面的例子所示： 
# 
#  
# 
#  
# Logs 表：
# +----+-----+
# | Id | Num |
# +----+-----+
# | 1  | 1   |
# | 2  | 1   |
# | 3  | 1   |
# | 4  | 2   |
# | 5  | 1   |
# | 6  | 2   |
# | 7  | 2   |
# +----+-----+
# 
# Result 表：
# +-----------------+
# | ConsecutiveNums |
# +-----------------+
# | 1               |
# +-----------------+
# 1 是唯一连续出现至少三次的数字。
#  
#  👍 368 👎 0

# 解法一
SELECT DISTINCT Num as "ConsecutiveNums" FROM (
SELECT Num,COUNT(1) as SerialCount FROM
    (SELECT Id,Num,
            ROW_NUMBER() over(order by id) -
            ROW_NUMBER() over(partition by Num order by Id) as SerialNumberSubGroup
     FROM Logs) as Sub
GROUP BY Num,SerialNumberSubGroup HAVING COUNT(1) >= 3) as Result

# 解法二
# 利用 lead 窗口函数，将num列上移一行得到 num1, 上移两行得到num2
select distinct num as ConsecutiveNums  from
    (
        select num, lead(num,1)over() as num1, lead(num,2)over() as num2
        from logs
    ) as c
where c.num = c.num1 and c.num1 = c.num2
