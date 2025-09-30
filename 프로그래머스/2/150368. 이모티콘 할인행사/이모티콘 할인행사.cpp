#include <bits/stdc++.h>

using namespace std;

int N;
int getAccount(int P, vector<int> &disc, vector<int> &emoticons) {
    int res = 0;
    for (int i = 0; i < N; i++) {
        if (disc[i] >= P) res += (emoticons[i] * double(100 - disc[i]) / 100);
    }
    return res;
}

vector<int> answer({0, 0});
vector<int> brt({10, 20, 30, 40});

void dfs(int idx, vector<int> &emoticons, vector<vector<int>> &users, vector<int> &disc) {
    if (idx == N) {
        vector<int> res(2, 0);
        for (auto &user : users) {
            int acc = getAccount(user[0], disc, emoticons);
            if (acc >= user[1]) res[0]++;
            else res[1] += acc;
        }
        answer = max(res, answer);
        return ;
    }
    for (auto &P : brt) {
        disc[idx] = P;
        dfs(idx + 1, emoticons, users, disc);
        // disc[idx] = 0;
    }
    
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    N = emoticons.size();
    
    vector<int> disc(N, 0);
    
    dfs(0, emoticons, users, disc);
    
    return answer;
}