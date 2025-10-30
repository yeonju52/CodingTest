#include <bits/stdc++.h>

using namespace std;

int dp[102][102];

int solution(int m, int n, vector<vector<int>> puddles) {
    for (auto &cur : puddles) dp[cur[0]][cur[1]] = -1;
    dp[1][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
        }
    }
    return dp[m][n];
}