SELECT title, rating FROM movies JOIN ratings ON movie_id = id WHERE year = 2010 ORDER by rating DESC, title