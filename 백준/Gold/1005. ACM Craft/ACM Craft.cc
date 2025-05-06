#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int T, N, K, W, deg[MAX], tmm[MAX], ans[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        memset(deg, 0, sizeof(deg));
        memset(tmm, 0, sizeof(tmm));
        memset(ans, 0, sizeof(ans));
        vector<int> adj[MAX];

        cin >> N >> K;
        for (int i = 1; i <= N; i++) cin >> tmm[i];
        while(K--) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            deg[v]++;
        }
        cin >> W;
        if (deg[W] == 0) { cout << tmm[W] << "\n"; continue; } 
        
        queue<int> q;
        for (int i = 1; i <= N; i++) if (deg[i] == 0) q.push(i);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if (u == W) break;
            for (int &v : adj[u]) {
                deg[v]--;
                ans[v] = max(ans[v], ans[u] + tmm[u]);
                if (deg[v] > 0) continue;
                q.push(v);
            }
        }

        cout << ans[W] + tmm[W] << "\n";
    }
}