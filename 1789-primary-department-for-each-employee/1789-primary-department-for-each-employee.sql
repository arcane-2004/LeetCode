select employee_id,
case when count(employee_id) = 1 then department_id
when count(employee_id) > 1 then sum((primary_flag = 'Y') * department_id)
end as department_id
from Employee
group by employee_id
