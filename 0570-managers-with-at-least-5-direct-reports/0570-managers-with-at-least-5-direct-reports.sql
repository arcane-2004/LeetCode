# Write your MySQL query statement below
with manager as(
    select
    managerId,
    count(*) as count
    from Employee
    group by managerId
)

select e.name 
from Employee as e
inner join manager as m 
on m.managerId = e.id
where m.count >= 5