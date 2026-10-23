from heapq import heappush, heappop, heapify

def solution(jobs):
    ret = 0
    jobs.sort()
    
    pq = []
    now = 0
    N = len(jobs)
    i = 0
    
    # 시간 짧은 거, 요청 시각 낮은 거, 작업 번호 작은 거
    while i < N or pq:
        while i < N and jobs[i][0] <= now:
            heappush(pq, (jobs[i][1], jobs[i][0]))
            i += 1
        if pq:
            t, s = heappop(pq)
            now += t
            ret += (now - s)
        else:
            now = jobs[i][0]
    
    return ret // N