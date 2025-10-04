#include <bits/stdc++.h>

using namespace std;

int popcount(int val) {
    int cnt = 0;
    while (val) {
        if (val & 1) cnt++;
        val >>= 1;
    }
    return cnt;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    int N = orders.size();
    
    unordered_set<char> alpha_set;
    vector<int> arr(N, 0);
    for (int i = 0; i < N; i++) {
        for (auto &c : orders[i]) {
            arr[i] += (1 << (c - 'A'));
            alpha_set.insert(c);
        }
    }
    
    int M = alpha_set.size();
    vector<char> alpha(alpha_set.begin(), alpha_set.end());
    sort(alpha.begin(), alpha.end());
    
    for (auto &cur : course) {
        vector<string> res;
        int mxCnt = 0;
        for (int brt = 0; brt < (1 << M); brt++) {
            if (popcount(brt) != cur) continue;
            string star = "";
            int tar = 0;
            for (int i = 0; i < M; i++) {
                if (brt &  (1 << i)) {
                    star += alpha[i];
                    tar += (1 << (alpha[i] - 'A'));   
                }
            }
            int cnt = 0;
            for (auto &other : arr) {
                if ((other & tar) == tar) cnt++;
            }
            if (cnt < 2) continue;
            if (mxCnt < cnt) {
                mxCnt = cnt;
                res.clear();
                res.push_back(star);
            }
            else if (mxCnt == cnt) {
                res.push_back(star);
            }
        }
        
        answer.insert(answer.end(), res.begin(), res.end());
    }
    sort(answer.begin(), answer.end());
    return answer;
}