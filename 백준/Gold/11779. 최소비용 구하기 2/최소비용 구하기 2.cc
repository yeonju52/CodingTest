#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
const long INF = 100000L * 100000L; // 10 ^ 10
int N, M;
vector<pair<long, int>> adj[MAX];
long dist[MAX];
int pre[MAX];

void dijkstra(int st, int ed);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    int st, ed;
    cin >> st >> ed;

    dijkstra(st, ed);

    // 이전 경로 탐색
    vector<int> path;
    path.push_back(ed);
    int cur = ed;
    
    while (cur != st) {
        path.push_back(pre[cur]);
        cur = pre[cur];
    }

    cout << dist[ed] << "\n";
    cout << path.size() << "\n";
    for (auto iter = path.rbegin(); iter < path.rend(); iter++) {
        cout << *iter << " ";
    }
}

void dijkstra(int st, int ed) {
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
    // 초기화
    fill(dist, dist + N + 1, INF);
    memset(pre, 0, sizeof(pre));
    dist[st] = 0;
    pq.push({dist[st], st});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int u = cur.second;
        if (cur.first != dist[u]) continue;
        for (auto &nxt : adj[u]) {
            int v = nxt.second, w = nxt.first;
            if (dist[v] <= dist[u] + w) continue;
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
            pre[v] = u;
        }
    }
}