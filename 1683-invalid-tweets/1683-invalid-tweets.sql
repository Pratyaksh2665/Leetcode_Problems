# Write your MySQL query statement below
SELECT distinct tweet_id
from Tweets
where length(content)>15;