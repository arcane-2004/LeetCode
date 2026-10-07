with distinct_date as(
    select distinct player_id,
    event_date
    from Activity
),

ranked as(
    select player_id,
    event_date,
    row_number() over(
        partition by player_id
        order by event_date asc
    )as rank_id
    from distinct_date
),

leading_date as(
    select player_id, event_date,
    lead(event_date) over(
        partition by player_id
        order by event_date
    )as next_date
    from ranked
    where rank_id <= 2
)

select
round(
    sum(case when datediff(next_date, event_date) = 1  then 1 else 0 end)
    / count(distinct player_id)
    , 2 
)as fraction
from leading_date

