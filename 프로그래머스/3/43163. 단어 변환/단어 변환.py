import sys
sys.setrecursionlimit(10**6)

def solution(begin, target, words):
    M = len(begin) # 글씨체
    N = len(words)
    
    # 변환가능한가
    def isValid(a, b):
        ret = 0
        for i in range(M):
            if a[i] != b[i]:
                ret += 1
        
        return True if ret == 1 else False
    
    vis = [0 for _ in range(N)]
    
    INF = 123456789
    ans = INF

    # 백트래킹 구현
    def bt(cur, dep):
        nonlocal ans
        if cur == target:
            ans = min(ans, dep)
            return
        if dep >= ans:
            return
        for i in range(N):
            if vis[i] or not isValid(cur, words[i]):
                continue
            vis[i] = 1
            bt(words[i], dep + 1)
            vis[i] = 0
    
    bt(begin, 0)
    
    return 0 if ans == INF else ans