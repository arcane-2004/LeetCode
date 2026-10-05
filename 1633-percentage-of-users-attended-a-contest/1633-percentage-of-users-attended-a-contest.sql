select contest_id,
round(
    (count(contest_id) / (
        select count(*) from Users) * 100
    ), 2 
) as percentage
from Register
-- inner join Users as u
-- on u.user_id = r.user_id
group by contest_id
order by percentage desc, contest_id
