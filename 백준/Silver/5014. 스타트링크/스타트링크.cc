#include <bits/stdc++.h>
using namespace std;

int F, S, G, U, D;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> F >> S >> G >> U >> D;
    vector<int> dp(F + 1, -1);
    
    queue<int> q;
    q.push(S);
    dp[S] = 0;

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == G) break;
        if (cur + U <= F && dp[cur + U] == -1) { dp[cur + U] = dp[cur] + 1; q.push(cur + U); }
        if (cur - D > 0 && dp[cur - D] == -1) { dp[cur - D] = dp[cur] + 1; q.push(cur - D); }
    }
    if (dp[G] == -1) cout << "use the stairs";
    else cout << dp[G];
}