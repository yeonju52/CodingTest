#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

const int MAX = 1001, INF = 0x3f3f3f3f;
int N, M, X;

vector<P> adj[MAX], rev[MAX];
int dst[MAX], ans[MAX];

void dikjstra(int st, const vector<P> arr[MAX]) {
    fill(dst, dst + N + 1, INF);
    priority_queue<P, vector<P>, greater<>> pq;

    dst[st] = 0;
    pq.push({dst[st], st});

    while(!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int u = p.second;
        if (dst[u] !=  p.first) continue;
        for (auto np : arr[u]) {
            int v = np.second, w = np.first;
            if (dst[v] > dst[u] + w) {
                dst[v] = dst[u] + w;
                pq.push({dst[v], v});
            }
        }
    }
    return ;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        rev[v].push_back({w, u});
    }
    
    dikjstra(X, adj);
    memcpy(ans, dst, sizeof(ans));

    dikjstra(X, rev);
    for (int i = 1; i <= N; i++) ans[i] += dst[i];
    cout << *max_element(ans + 1, ans + N + 1);
}