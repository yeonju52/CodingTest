#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
int N;
int p[MAX];
vector<int> adj[MAX];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    p[1] = 0;

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for (int &nxt : adj[cur]) {
            if(p[nxt] > 0) continue;
            q.push(nxt);
            p[nxt] = cur;
        }
    }
    for (int i = 2; i <= N; i++) cout << p[i] << "\n";
}