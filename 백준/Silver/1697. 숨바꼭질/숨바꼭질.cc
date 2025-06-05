#include <bits/stdc++.h>
using namespace std;

int N, K, dp[100001];

int main() {
    cin >> N >> K;

    queue<int> q;
    fill(dp, dp + 100001, 100001);
    dp[N] = 0;
    q.push(N);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == K) break;
        if (cur + 1 < 100001 && dp[cur + 1] > dp[cur] + 1) {
            dp[cur + 1] = dp[cur] + 1;
            q.push(cur + 1);
        }
        if (cur - 1 >= 0 && dp[cur - 1] > dp[cur] + 1) {
            dp[cur - 1] = dp[cur] + 1;
            q.push(cur - 1);
        }
        if (cur * 2 <= 100000 && dp[cur * 2] > dp[cur] + 1) {
            dp[cur * 2] = dp[cur] + 1;
            q.push(cur * 2);
        }
    }
    cout << dp[K];

    return 0;
}