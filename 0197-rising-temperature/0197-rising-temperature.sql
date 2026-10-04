with previous as(
    select id,
    temperature,
    recordDate as curr_date,
    lag(recordDate) over(
        order by recordDate asc
    )as previous_date,
    lag(temperature) over(
        order by recordDate asc
    )as previous_temp
    from Weather
)

select id
from previous
where temperature > previous_temp
and datediff(curr_date, previous_date) = 1
