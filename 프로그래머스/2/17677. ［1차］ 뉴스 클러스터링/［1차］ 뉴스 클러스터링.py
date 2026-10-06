def solution(str1, str2):
    answer = 0
    str1, str2 = str1.lower(), str2.lower()
    arr1 = [str1[i:i+2] for i in range(len(str1) - 1) if str1[i:i+2].isalpha()]
    arr2 = [str2[i:i+2] for i in range(len(str2) - 1) if str2[i:i+2].isalpha()]
    
    # 다중교집합
    inset = []
    for s1 in arr1: # fr
        if s1 in arr2:
            arr2.remove(s1)
            inset.append(s1)
    
    # 다중합집합
    uniset = arr1 + arr2
    
    # arr2 원복
    arr2 += inset
    
    
    if len(arr1) == 0 and len(arr2) == 0:
        answer = 1 * 65536
    else:
        answer = len(inset) * 65536 // len(uniset)
    
    return answer