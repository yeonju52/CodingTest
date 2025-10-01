#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> dict = {{"cpp", 256}, {"java", 128}, {"python", 64},
                                   {"backend", 32}, {"frontend", 16},
                                   {"junior", 8}, {"senior", 4},
                                   {"chicken", 2}, {"pizza", 1},
                                   {"-", 0}};

unordered_map<int, vector<int>> arr;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for (auto &S : info) {
        int res = 0;
        for (int i = 0; i < 4; i++) {
            int idx = S.find(" ");
            res |= dict[S.substr(0, idx)];
            S = S.substr(idx + 1);
        }
        arr[res].push_back(stoi(S));
    }
    
    for (auto &[k, v] : arr) {
        sort(v.begin(), v.end());
    }
    
    for (auto &Q : query) {
        int res = 0;
        for (int i = 0; i < 3; i++) {
            int idx = Q.find(" ");
            res |= dict[Q.substr(0, idx)];
            Q = Q.substr(idx + 5);
        }
        int idx = Q.find(" ");
        res |= dict[Q.substr(0, idx)];
        Q = Q.substr(idx + 1);
        int scr = stoi(Q);
        
        // 비교
        int cnt = 0;
        for (auto &[k, v] : arr) {
            if ((k & res) == res) {
                cnt += (v.size() - (lower_bound(v.begin(), v.end(), scr) - v.begin()));
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}