#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const int MAX = 201;
const int INF = 0x3f3f3f3f;

int N;
vector<pii> adj[MAX];

vector<int> dijkstra(int S) {
    vector<int> dist(N, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (dist[u] < cost) continue;

        for (auto &[w, v] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    N = n;
    s--, a--, b--;

    for (auto &fare : fares) {
        int c = fare[0] - 1, d = fare[1] - 1, f = fare[2];
        adj[c].push_back({f, d});
        adj[d].push_back({f, c});
    }

    vector<int> fromS = dijkstra(s);
    vector<int> fromA = dijkstra(a);
    vector<int> fromB = dijkstra(b);

    int ans = INF;
    for (int k = 0; k < n; k++) {
        if (fromS[k] == INF || fromA[k] == INF || fromB[k] == INF) continue;
        ans = min(ans, fromS[k] + fromA[k] + fromB[k]);
    }

    return ans;
}
