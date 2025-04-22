#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
const int MAX = 20000;
int V, E;
int st;
vector<pair<int, int>> adj[MAX];
int dst[MAX];

void dijkstra(int st);

int main() {
    cin >> V >> E >> st;
    st -=  1;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({w, v - 1});
    }
    
    fill(dst, dst + V, INF);
    dijkstra(st);
    for (int i = 0; i < V; i++) {
        if (dst[i] == INF) cout << "INF\n";
        else cout << dst[i] << "\n";
    }
    return 0;
}

void dijkstra(int st) {
    // 최단거리 초기화
    priority_queue<pair<int, int>, 
                vector<pair<int, int>>,
                greater<pair<int, int>>> pq;
    dst[st] = 0;
    pq.push({dst[st], st});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int u = cur.Y, w = cur.X;
        if (dst[u] != w) continue; // 왜? 다르면 왜 탐색 안 함?
        for (auto &nxt : adj[u]) {
            int v = nxt.Y, nw = nxt.X;
            if (dst[v] <= dst[u] + nw) continue;
            dst[v] = dst[u] + nw;
            pq.push({dst[v], v});
        }
    }
}