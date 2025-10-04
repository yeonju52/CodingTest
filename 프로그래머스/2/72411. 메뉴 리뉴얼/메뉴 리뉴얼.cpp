#include <bits/stdc++.h>

using namespace std;

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
        vector<int> brt(M, 0);
        fill(brt.end() - cur, brt.end(), 1);
        vector<string> res;
        int mxCnt = 0;
        do {
            string star = "";
            int tar = 0;
            for (int i = 0; i < M; i++) {
                if (brt[i] == 1) {
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
        } while(next_permutation(brt.begin(), brt.end()));
        
        answer.insert(answer.end(), res.begin(), res.end());
    }
    sort(answer.begin(), answer.end());
    return answer;
}