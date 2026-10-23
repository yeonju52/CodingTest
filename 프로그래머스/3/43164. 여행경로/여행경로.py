import sys
sys.setrecursionlimit(10**6)

from collections import deque, defaultdict

def solution(tickets):
    answer = []
    
    tickets.sort(key=lambda x: (x[0], x[1]))
    st = "ICN"
    
    arr = defaultdict(list)
    for i, (s, e) in enumerate(tickets):
        arr[s].append((e, i))
    
    N = len(tickets)
    vis = [0 for _ in range(N)]
    
    print(arr)
    path = deque(["ICN"])
    def dfs(dep, path):
        nonlocal answer
        if dep == N:
            answer = list(path)
            return
        if answer: return # 가지 치기 필수
        for nxt, i in arr[path[-1]]:
            if vis[i]: continue
            path.append(nxt)
            vis[i] = 1
            dfs(dep + 1, path)
            path.pop()
            vis[i] = 0
    
    dfs(0, path)
    return answer