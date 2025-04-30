#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

int N, M;
vector<int> adj[MAX]; // 방향그래프 (>)
vector<int> rev[MAX]; // 방향그래프 (<)

int vis[MAX];

void bfs(const vector<int> (&arr)[MAX], int st);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        memset(vis, 0, sizeof(vis));
        bfs(adj, i);
        bfs(rev, i);
        
        cout << N - count(vis, vis + N + 1, 1) << "\n";
    }
}

void bfs(const vector<int> (&arr)[MAX], int st) {
    queue<int> q;
    vis[st] = 1;
    q.push(st);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto& v: arr[cur]) {
            if (vis[v]) continue;
            vis[v] = 1;
            q.push(v);
        }
    }

}