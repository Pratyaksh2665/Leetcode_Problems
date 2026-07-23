# Write your MySQL query statement below
select today.id from Weather as today
where EXISTS
    (select 1 from Weather as yesterday
        where yesterday.temperature<today.temperature
        AND 
        DATEDIFF(today.recordDate, yesterday.recordDate)=1);
