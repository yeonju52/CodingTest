#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int &a, int &b){
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), cmp);
    
    int len = citations.size();
    int idx = len;
    while(idx--){
        answer = max(answer, min(idx + 1, citations[idx]));
    }
    return answer;
}