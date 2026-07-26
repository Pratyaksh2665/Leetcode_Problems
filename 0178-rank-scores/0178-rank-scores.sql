SELECT score,
       rnk AS `rank`
FROM (
    SELECT score,
           DENSE_RANK() OVER (ORDER BY score DESC) AS rnk
    FROM Scores
) t;