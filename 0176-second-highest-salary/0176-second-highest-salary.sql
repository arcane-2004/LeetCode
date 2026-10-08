-- select max(salary) as SecondHighestSalary
-- from Employee
-- where salary < (
--     select max(salary)
--     from Employee
-- )

with ranked as(
    select salary,
    dense_rank() over(
        order by salary desc
    )as rank_id
    from Employee
)

select max(salary) as SecondHighestSalary
from ranked 
where rank_id = 2

