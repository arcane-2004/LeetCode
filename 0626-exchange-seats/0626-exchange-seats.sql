with newTable as(
    select *,
    lag(id) over( order by id) as prev,
    lead(id) over( order by id) as next
    from Seat
)

select 
case when ((id % 2 = 1) and next is not null) then next
when (id % 2 = 0) then prev
else id end as id,
student
from newTable
order by id