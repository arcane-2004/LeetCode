with first_login as(
    select player_id,
    min(event_date) as first_date
    from Activity
    group by player_id
)

select
round(
    sum(
        case when exists(
            select 1
            from Activity a
            where a.player_id = f.player_id
            and a.event_date = date_add(f.first_date, interval 1 day)
        ) then 1 else 0 end
    ) / count(distinct f.player_id)
    , 2
)as fraction
from first_login f