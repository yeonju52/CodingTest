#include <bits/stdc++.h>
using namespace std;

const int MAX = 500;
int T, N, A[MAX], prefix[MAX], dp[MAX][MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        memset(A, 0, sizeof(A));
        memset(prefix, 0, sizeof(prefix));
        memset(dp, 0, sizeof(dp));

        cin >> N;
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) prefix[i + 1] = prefix[i] + A[i];

        for (int len = 1; len < N; len++) {
            for (int st = 0; st + len < N; st++) {
                int ed = st + len;
                dp[st][ed] = INT_MAX;
                for (int k = st; k < ed; k++) {
                    dp[st][ed] = min(dp[st][st + len], dp[st][k] + dp[k+1][ed] + prefix[ed+1] - prefix[st]);
                }
            }
        }
        cout << dp[0][N - 1] << "\n";
    }
}