#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T--) {
        cin >> N;
        vector<int> arr(N, 0);
        for (auto &a: arr) cin >> a;
        cin >> M;
        vector<int> dp(M + 1, 0);
        dp[0] = 1;
        for (auto &a: arr) {
            for (int j = a; j <= M; j++) {
                dp[j] += dp[j - a];
            }
        }
        cout << dp[M] << "\n";
    }
}