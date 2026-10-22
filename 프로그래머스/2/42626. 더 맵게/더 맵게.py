from heapq import heappush, heappop, heapify

def solution(scoville, K):
    ans = 0
    
    pq = scoville
    heapify(pq)
    
    while len(pq) > 1 and pq[0] < K:
        x, y = heappop(pq), heappop(pq)
        cur = x + (y * 2)
        heappush(pq, (cur))
        ans += 1
    
    if pq[0] < K:
        return -1
    return ans