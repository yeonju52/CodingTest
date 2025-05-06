#include <bits/stdc++.h>
using namespace std;

const int MAX = 32001;
int N, M, deg[MAX];
vector<int> adj[MAX], ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while(M--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    for (int i = 1; i <= N; i++) if(deg[i] == 0) pq.push(i);
    while(!pq.empty()) {
        int u = pq.top(); pq.pop();
        ans.push_back(u);
        for (int &v : adj[u]) {
            deg[v]--;
            if (deg[v] > 0) continue;
            pq.push(v);
        }
    }

    for (int &v : ans) cout << v << " ";
}