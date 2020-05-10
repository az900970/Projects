SELECT
movies.title
FROM
movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE
movies.id IN
(
SELECT
movies.id
FROM
movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE
people.name = "Johnny Depp")

INTERSECT

SELECT
movies.title
FROM
movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE
movies.id IN
(
SELECT
movies.id
FROM
movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE
people.name = "Helena Bonham Carter")