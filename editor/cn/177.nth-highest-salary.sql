-- 编写一个 SQL 查询，获取 Employee 表中第 n 高的薪水（Salary）。 
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
--  例如上述 Employee 表，n = 2 时，应返回第二高的薪水 200。如果不存在第 n 高的薪水，那么查询应返回 null。 
-- 
--  +------------------------+
-- | getNthHighestSalary(2) |
-- +------------------------+
-- | 200                    |
-- +------------------------+
--  
--  👍 416 👎 0

# 解法一
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    RETURN (
        # Write your MySQL query statement below.
        SELECT
            A.Salary
        FROM (
            SELECT
                Salary, ROW_NUMBER() OVER(ORDER BY Salary DESC) AS 'Nth'
            FROM
                (
                    SELECT DISTINCT Salary FROM Employee
                ) B
        ) A
        WHERE
            A.Nth=N
    );
END

# 解法二
# 使用 dense_rank 达到同样的效果
# 实际上，在mysql8.0中有相关的内置函数，而且考虑了各种排名问题：
# row_number(): 同薪不同名，相当于行号，例如3000、2000、2000、1000排名后为1、2、3、4
# rank(): 同薪同名，有跳级，例如3000、2000、2000、1000排名后为1、2、2、4
# dense_rank(): 同薪同名，无跳级，例如3000、2000、2000、1000排名后为1、2、2、3
# ntile(): 分桶排名，即首先按桶的个数分出第一二三桶，然后各桶内从1排名，实际不是很常用
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    RETURN (
       # Write your MySQL query statement below.
       SELECT
           DISTINCT salary
       FROM
           (SELECT
                salary, dense_rank() over(ORDER BY salary DESC) AS rnk
            FROM
                employee) tmp
       WHERE rnk = N
   );
END

# 解法三
# 使用自定义变量, 先排序之后计算出排名，然后再进行处理
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    RETURN (
        # Write your MySQL query statement below.
        SELECT
            DISTINCT salary
        FROM
            (SELECT
                 salary, @r:=IF(@p=salary, @r, @r+1) AS rnk,  @p:= salary
             FROM
                 employee, (SELECT @r:=0, @p:=NULL)init
             ORDER BY
                 salary DESC) tmp
        WHERE rnk = N
    );
END
