#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P;

const int MAX = 801, INF = 3 * 799 * 1000 + 1; // INF = 0x3f3f3f3f, 89%에서 틀림. INF를 3개 더할 때 오버플로우 발생
int N, V;

vector<P> adj[MAX];
int dst[MAX];

int dikjstra(int st, int ed) {
    fill(dst, dst + N + 1, INF);
    priority_queue<P, vector<P>, greater<>> pq;

    dst[st] = 0;
    pq.push({dst[st], st});

    while(!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int u = p.second;
        // if (ed == u) break; // 해도 되나?
        if (dst[u] !=  p.first) continue;
        for (auto np : adj[u]) {
            int v = np.second, w = np.first;
            if (dst[v] > dst[u] + w) {
                dst[v] = dst[u] + w;
                pq.push({dst[v], v});
            }
        }
    }
    return dst[ed];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> V;
    for (int i = 0; i < V; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int p1, p2;
    cin >> p1 >> p2;

    // st - (p1, p2)
    dikjstra(1, N);
    int st_p1 = dst[p1], st_p2 = dst[p2];
    // p1 - p2: 필수 정점임, 필수 간선이 아님. 문제 이해 주의
    int p1_p2 = dikjstra(p1, p2);;
    
    // (p1, p2) - ed
    int p1_ed = dikjstra(p1, N);
    int p2_ed = dikjstra(p2, N);
    
    int ans = min(st_p1 + p1_p2 + p2_ed, st_p2 + p1_p2 + p1_ed);
    cout << (ans >= INF ? -1 : ans);
}