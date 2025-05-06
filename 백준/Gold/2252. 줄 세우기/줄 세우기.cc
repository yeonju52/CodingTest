#include <bits/stdc++.h>
using namespace std;

const int MAX = 32001;

int N, M;
vector<int> deg, ans;
vector<int> adj[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    deg.resize(N + 1, 0);
    while(M--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for (auto &v : adj[cur]) {
            deg[v]--;
            if (deg[v] > 0) continue;
            q.push(v);
        }
    }

    for(auto& v : ans) cout << v << " ";
}