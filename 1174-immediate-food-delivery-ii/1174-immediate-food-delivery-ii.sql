
    select 
    round(
        (sum(case when order_date = customer_pref_delivery_date then 1 else 0 end)
            / count(*)) * 100
            , 2
    )as immediate_percentage
    from Delivery as d1
    where order_date = (
        select min(order_date)
        from Delivery as d2
        where d2.customer_id = d1.customer_id
    )


