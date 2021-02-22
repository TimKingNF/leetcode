# 编写一个 SQL 查询，来删除 Person 表中所有重复的电子邮箱，重复的邮箱里只保留 Id 最小 的那个。 
# 
#  +----+------------------+
# | Id | Email            |
# +----+------------------+
# | 1  | john@example.com |
# | 2  | bob@example.com  |
# | 3  | john@example.com |
# +----+------------------+
# Id 是这个表的主键。
#  
# 
#  例如，在运行你的查询语句之后，上面的 Person 表应返回以下几行: 
# 
#  +----+------------------+
# | Id | Email            |
# +----+------------------+
# | 1  | john@example.com |
# | 2  | bob@example.com  |
# +----+------------------+
#  
# 
#  
# 
#  提示： 
# 
#  
#  执行 SQL 之后，输出是整个 Person 表。 
#  使用 delete 语句。 
#  
#  👍 333 👎 0

# 解法一
# 自连接效率更高些
DELETE
    A.*
FROM
    Person A, Person B
WHERE
    A.Email=B.Email AND
    A.Id > B.Id
;

# 解法二
delete from person
where
    id not in (
        select t.id from (select min(id) id from person group by email) t
    )
;