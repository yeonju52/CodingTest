#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P;

vector<P> adj[1001];
vector<int> path[1001];
int N, M, deg[1001], ans[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        deg[v]++;
    }

    queue<int> q;
    q.push(1);
    path[1].push_back(1);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto &p : adj[cur]) {
            int nxt = p.second, dst = p.first;
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
            if (ans[nxt] < ans[cur] + dst) {
                ans[nxt] = ans[cur] + dst;
                path[nxt] = path[cur];
                path[nxt].push_back(nxt);
            }
        }
    }

    cout << ans[1] << "\n";
    for (auto &p : path[1]) cout << p << " ";
}