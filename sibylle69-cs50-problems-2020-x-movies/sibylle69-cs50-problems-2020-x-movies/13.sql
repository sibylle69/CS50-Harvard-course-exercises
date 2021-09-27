SELECT DISTINCT people.name FROM
movies JOIN (stars JOIN people ON stars.person_id = people.id) ON stars.movie_id = movies.id
WHERE movies.id IN
(
    SELECT movies.id FROM movies JOIN (stars JOIN people ON stars.person_id = people.id) ON movies.id = stars.movie_id
    WHERE people.name = "Kevin Bacon" AND people.birth = 1958
)
AND NOT people.name = "Kevin Bacon"