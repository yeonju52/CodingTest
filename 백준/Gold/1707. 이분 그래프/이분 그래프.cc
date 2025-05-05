#include <bits/stdc++.h>
using namespace std;

const int MAX = 20001;

int K, V, E;

int vis[MAX];

bool bfs(int u, vector<int> (&adj)[MAX]) {
    queue<int> q;
    q.push(u);
    vis[u] = 2;

    while(!q.empty()) {
        u = q.front(); q.pop();
        for (int &v : adj[u]) {
            if (vis[v] == vis[u]) return false;
            if (vis[v] > 0) continue;
            q.push(v);
            vis[v] = vis[u] ^ 1;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;

    while (K--) {
        vector<int> adj[MAX];
        memset(vis, 0, sizeof(vis));
        cin >> V >> E;
        int u, v;
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool is_bipartite = true;
        for (int i = 1; i <= V; i++) {
            if (vis[i] == 0) {
                if (!bfs(i, adj)) {
                    is_bipartite = false;
                    break;
                }
            }
        }

        cout << (is_bipartite ? "YES\n" : "NO\n");
    }
}