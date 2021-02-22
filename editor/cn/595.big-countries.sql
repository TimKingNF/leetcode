# 这里有张 World 表 
# 
#  
# +-----------------+------------+------------+--------------+---------------+
# | name            | continent  | area       | population   | gdp           |
# +-----------------+------------+------------+--------------+---------------+
# | Afghanistan     | Asia       | 652230     | 25500100     | 20343000      |
# | Albania         | Europe     | 28748      | 2831741      | 12960000      |
# | Algeria         | Africa     | 2381741    | 37100000     | 188681000     |
# | Andorra         | Europe     | 468        | 78115        | 3712000       |
# | Angola          | Africa     | 1246700    | 20609294     | 100990000     |
# +-----------------+------------+------------+--------------+---------------+
#  
# 
#  如果一个国家的面积超过 300 万平方公里，或者人口超过 2500 万，那么这个国家就是大国家。 
# 
#  编写一个 SQL 查询，输出表中所有大国家的名称、人口和面积。 
# 
#  例如，根据上表，我们应该输出: 
# 
#  
# +--------------+-------------+--------------+
# | name         | population  | area         |
# +--------------+-------------+--------------+
# | Afghanistan  | 25500100    | 652230       |
# | Algeria      | 37100000    | 2381741      |
# +--------------+-------------+--------------+
#  
#  👍 155 👎 0

# 对于单列来说，用or是没有任何问题的，但是or涉及到多个列的时候，每次select只能选取一个index，
# 如果选择了area，population就需要进行table-scan，即全部扫描一遍，但是使用union就可以解决这个问题，
# 分别使用area和population上面的index进行查询。
# 但是这里还会有一个问题就是，UNION会对结果进行排序去重，可能会降低一些performance
# (这有可能是方法一比方法二快的原因），所以最佳的选择应该是两种方法都进行尝试比较。
# （stackoverflow链接: https://stackoverflow.com/questions/13750475/sql-performance-union-vs-or）

SELECT
    name, population, area
FROM
    world
WHERE
        area > 3000000

UNION

SELECT
    name, population, area
FROM
    world
WHERE
        population > 25000000
;
