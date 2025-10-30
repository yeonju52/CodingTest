#include <bits/stdc++.h>

using namespace std;


int solution(vector<int> money) {
    int N = money.size();
    vector<vector<int>> dp(2, vector<int>(N, 0));
    
    dp[0][0] = money[0];
    for (int i = 1; i < N; i++) {
        if (i != N - 1) dp[0][i] = max(dp[0][i - 2] + money[i], dp[0][i - 1]);
        dp[1][i] = max(dp[1][i - 2] + money[i], dp[1][i - 1]);
    }
    return max(dp[0][N - 2], dp[1][N - 1]);
}