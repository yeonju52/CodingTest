#include <bits/stdc++.h>
using namespace std;

const int INF = 5000001;
int N, M;
vector<long long> dist;
struct uvw {
    int u, v, w;
};

vector<uvw> adj;

bool bf(int st) {
    dist[st] = 0;
    for (int i = 0; i < N; i++) {
        for (auto &edge : adj) {
            int u = edge.u, v = edge.v, w = edge.w;
            if (dist[u] != INF && dist[v] > dist[u] + (1LL * w)) {
                dist[v] = dist[u] + w;
                if (i == N - 1) return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    dist.resize(N + 1, INF);
    adj.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> adj[i].u >> adj[i].v >> adj[i].w;
    }

    if (bf(1)) cout << "-1\n"; // 음수 간선
    else {
        for (int i = 2; i <= N; i++) {
            if(dist[i] == INF) cout << "-1\n"; // 경로 없는 경우
            else cout << dist[i] << "\n";
        }
    }
}