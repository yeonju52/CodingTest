-- 코드를 입력하세요
SELECT book_id, author_name, DATE_FORMAT(published_date, "%Y-%m-%d") as published_date
FROM BOOK b
LEFT JOIN AUTHOR a on a.author_id = b.author_id
WHERE b.category = "경제"
ORDER BY published_date ASC;