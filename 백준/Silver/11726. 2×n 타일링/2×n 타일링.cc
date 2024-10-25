#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    dp[1] = 1, dp[2] = 2; // dp[3] = d[2] + d[1];
    for (int n = 3; n <= N; n++){
        dp[n] = (dp[n - 1] + dp[n - 2]) % 10007;
    }
    cout << dp[N] << "\n";
}