def letterCombinations(digits):
    dictionary={"2":"abc", "3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"}
    
    result=[]

    if len(digits)==0:
        return result
    dfs(digits,0,dictionary,'',result)
    return result
    

def dfs(nums, index, dictionary, path, result):
    if index==len(nums):
        result.append(path)
        return
    
    letters=dictionary[nums[index]]
    for letter in letters:
        dfs(nums, index+1, dictionary, path+letter,result)

# sol=Solution()
print(letterCombinations("23"))