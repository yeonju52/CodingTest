def solution(s):
    answer = []
    arr = [list(map(int, x.split(','))) for x in s[2:-2].split('},{')]
    arr.sort(key=len)
    for x in arr:
        answer.append((set(x) - set(answer)).pop())
    return answer