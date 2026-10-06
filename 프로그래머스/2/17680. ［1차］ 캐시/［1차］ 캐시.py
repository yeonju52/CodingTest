from collections import deque

def solution(cacheSize, cities):
    answer = 0
    dq = deque(maxlen = cacheSize)
    for c in cities:
        c = c.lower()
        if c in dq:
            answer += 1
            dq.remove(c)
        else:
            answer += 5
        dq.append(c)
    return answer