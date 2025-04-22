#include <bits/stdc++.h>
using namespace std;

const int INF = 100001;
const int MAX = 100001;
int dp[MAX];

int main() {
    int N, K;
    cin >> N >> K;

    int st = N;
    fill(dp, dp + MAX, INF);
    dp[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dp[st], st});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int i = cur.second, w = cur.first;
        if (w != dp[i]) continue;
        if (i - 1 >= 0 && dp[i - 1] > w + 1) {
            dp[i - 1] = w + 1;
            pq.push({dp[i - 1], i - 1});
        }
        if (i + 1 <= MAX && dp[i + 1] > w + 1) {
            dp[i + 1] = w + 1;
            pq.push({dp[i + 1], i + 1});
        }
        if (i * 2 <= MAX && dp[i * 2] > w) {
            dp[i * 2] = w;
            pq.push({dp[i * 2], i * 2});
        }
    }
    
    cout << dp[K];
    return 0;
}