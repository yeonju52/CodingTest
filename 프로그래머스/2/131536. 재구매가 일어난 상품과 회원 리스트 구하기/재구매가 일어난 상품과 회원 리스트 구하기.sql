-- 코드를 입력하세요
SELECT user_id as USER_ID, product_id as PRODUCT_ID
FROM ONLINE_SALE
GROUP BY user_id, product_id
HAVING COUNT(*) > 1
ORDER BY user_id ASC, product_id DESC;