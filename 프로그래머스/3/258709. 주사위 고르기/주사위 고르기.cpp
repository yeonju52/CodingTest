#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> arr, rev;
vector<vector<int>> rec, rrec;

void record_dice(string brt, vector<vector<int>> &dice) {
    int M = arr.size();
    for (int i = 0; i < M; i++) { // 주사위의 조합
        int ret = 0;
        for (auto &cur : brt) ret += dice[i][cur];
        rec[i].push_back(ret);
        int ret2 = 0;
        for (auto &cur : brt) ret2 += dice[i][cur];
        rec[i].push_back(ret);
    }
}

void dice_comb(int idx, int sum, vector<int> &team, vector<vector<int>> &dice, vector<int> &res) {
    if (idx == team.size()) {
        res.push_back(sum);
        return;
    }
    for (int cur = 0; cur < 6; cur++) {
        dice_comb(idx + 1, sum + dice[team[idx]][cur], team, dice, res);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> ans;
    
    N = dice.size();
    
    vector<int> tmp(N, 0);
    fill(tmp.end() - N / 2, tmp.end(), 1);
    
    int mxWin = -1;
    do {
        vector<int> A, B;
        for (int i = 0; i < N; i++) {
            if (tmp[i]) A.push_back(i);
            else B.push_back(i);
        }
        vector<int> arrA, arrB;
        dice_comb(0, 0, A, dice, arrA);
        dice_comb(0, 0, B, dice, arrB);
        
        sort(arrB.begin(), arrB.end());
        
        long long win = 0;
        for (auto &x : arrA) {
            win += lower_bound(arrB.begin(), arrB.end(), x) - arrB.begin();
        }
        
        if (mxWin < win) {
            mxWin = win;
            ans = A;
        }
    } while(next_permutation(tmp.begin(), tmp.end()));
    
    for (auto &a : ans) a++;
    return ans;
}