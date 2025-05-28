#include <bits/stdc++.h>
using namespace std;

const int MAX = 15 + 1;

int N, t, p, dp[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t >> p;
        if (i > 0) dp[i] = max(dp[i - 1], dp[i]);
        if (i + t <= N) dp[i + t] = max(dp[i + t], dp[i] + p);
    }
    cout << *max_element(dp, dp + N + 1);
}