#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    int tmp = arr[0];
    vector<int> answer = {arr[0]};
    
    for (int cur : arr){
        if (cur != tmp) answer.push_back(cur);
        tmp = cur;
    }
    return answer;
}