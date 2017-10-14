/*
There is a table World

+-----------------+------------+------------+--------------+---------------+
| name            | continent  | area       | population   | gdp           |
+-----------------+------------+------------+--------------+---------------+
| Afghanistan     | Asia       | 652230     | 25500100     | 20343000      |
| Albania         | Europe     | 28748      | 2831741      | 12960000      |
| Algeria         | Africa     | 2381741    | 37100000     | 188681000     |
| Andorra         | Europe     | 468        | 78115        | 3712000       |
| Angola          | Africa     | 1246700    | 20609294     | 100990000     |
+-----------------+------------+------------+--------------+---------------+

A country is big if it has an area of bigger than 3 million square km or a population of more than 25 million.

Write a SQL solution to output big countries' name, population and area.

For example, according to the above table, we should output:

+--------------+-------------+--------------+
| name         | population  | area         |
+--------------+-------------+--------------+
| Afghanistan  | 25500100    | 652230       |
| Algeria      | 37100000    | 2381741      |
+--------------+-------------+--------------+

*/

/*Solution 1 with OR clause */

SELECT name, population, area FROM World where area > 3000000 OR population > 25000000 ; 

/*Solution 2 with UNION clause*/

SELECT name, population, area FROM World WHERE area > 3000000

UNION

SELECT name, population, area FROM World WHERE population > 25000000; 

/*Solution 3 testing the concept the dot operator, in the FROM clause we named
an alias for World with "a", and it follows that we can select from table a, but
we do not have to*/

SELECT a.name, a.population, a.area FROM World a where a.area > 3000000 OR a.population > 25000000 ; 