#include <bits/stdc++.h>

using namespace std;

vector<int> arr[1000001];
int used[100001];

vector<int> solution(string s) {
    vector<int> answer;
    
    s = s.substr(1, s.size() - 2);
    
    stringstream ss(s);
    string token;
    int N = 0;
    
    while (getline(ss, token, '}')) {
        if(token[0] == ',') token = token.substr(1);
        if(token[0] == '{') token = token.substr(1);
        vector<int> tmp;
        int idx = token.find(',');
        while(idx > 0) {
            tmp.push_back(stoi(token.substr(0, idx)));
            token = token.substr(idx + 1);
            idx = token.find(',');
        }
        tmp.push_back(stoi(token));
        arr[tmp.size()] = tmp;
        N = max(N, (int)tmp.size());
    }
    
    for (int i = 1; i <= N; i++) {
        for (auto &cur : arr[i]) {
            if (!used[cur]) {
                answer.push_back(cur);
                used[cur] = 1;
                break;
            }
        }
    }
    
    return answer;
}