with ranked as (
    select d.name as Department, e.name as Employee, e.salary as Salary,
    dense_rank() over(
        partition by d.id
        order by salary desc 
    ) as salary_rank
    from employee as e
    inner join department as d
    on e.departmentId = d.id
)

select Department, Employee, Salary from ranked
where salary_rank <= 3