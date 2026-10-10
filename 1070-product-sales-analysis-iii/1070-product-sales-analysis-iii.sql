with ranked as(
    select product_id,
    min(year) as first_year
    from Sales
    group by product_id
)

select s.product_id, 
s.year as first_year,
s.quantity,
s.price
from Sales s
join ranked r
on s.product_id = r.product_id
and s.year = r.first_year