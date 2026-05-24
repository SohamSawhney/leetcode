# Write your MySQL query statement below
select name
FROM Customer
where referee_id IS NULL
OR
referee_id!=2;