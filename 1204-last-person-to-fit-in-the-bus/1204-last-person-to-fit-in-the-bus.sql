
with summed as(
    select *, 
    sum(weight) over(
        order by turn
        rows between unbounded preceding and current row
    ) as total
    from Queue
)


select person_name from summed
where total <= 1001
order by total desc
limit 1

