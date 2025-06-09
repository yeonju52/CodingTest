#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;
const int MAX = 50001, INF = 0x3f3f3f3f;

int N, M, dist[MAX];
vector<P> adj[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    fill(dist, dist + N + 1, INF);
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[1] = 0;
    pq.push({dist[1], 1});

    while(!pq.empty()) {
        auto p = pq.top(); pq.pop(); // 으잉? 참조 붙이면, 안됨. pop되서 없어진 거 참조하잖아.
        int cur = p.second;
        if (p.first != dist[cur]) continue;
        for (auto &np : adj[cur]) {
            int nxt = np.second, nw = np.first;
            if (dist[nxt] > dist[cur] + nw) {
                dist[nxt] = dist[cur] + nw;
                pq.push({dist[nxt], nxt}); // 누적 거리로 넣어야지!
            }
        }
    }
    cout << dist[N];
}