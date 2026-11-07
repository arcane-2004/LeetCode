SELECT user_id,
concat(upper(left(name, 1)), lower(substring(name, 2))) as  name
FROM Users
order by user_id
