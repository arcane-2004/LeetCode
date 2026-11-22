# Write your MySQL query statement below
-- with new as( 
-- select *,
-- row_number() over(
--     partition by email
--     order by id
-- )as ranked
-- from Person)

-- delete from new
-- where ranked != 1

DELETE FROM Person
WHERE id IN (
    SELECT id FROM (
        SELECT 
            id, 
            ROW_NUMBER() OVER (PARTITION BY email ORDER BY id) AS ranked
        FROM Person
    ) sub
    WHERE ranked != 1
);
