from collections import deque

def solution(maps):
    answer = 0
    
    n, m = len(maps), len(maps[0])
    
    vis = [[0 for _ in range(m)] for _ in range(n)]
    
    dq = deque()
    vis[0][0] = 1
    dq.append((0, 0))
    
    if maps[0][0] == 0 or maps[n-1][m-1] == 0: return -1
    
    while dq:
        x, y = dq.popleft()
        if x == n - 1 and y == m - 1:
            break
        for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
            nx, ny = x + dx, y + dy
            if not(0 <= nx < n and 0 <= ny < m) or vis[nx][ny] != 0 or maps[nx][ny] == 0:
                continue
            
            dq.append((nx, ny))
            vis[nx][ny] = vis[x][y] + 1
    
    return -1 if vis[n-1][m-1] == 0 else vis[n-1][m-1]