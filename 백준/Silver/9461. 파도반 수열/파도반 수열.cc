#include <bits/stdc++.h>
using namespace std;

int T, N;
long long dp[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2;
    for (int i = 6; i <= 100; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    cin >> T;
    while (T--) {
        cin >> N;
        cout << dp[N] << "\n";
    }
}