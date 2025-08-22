#include <bits/stdc++.h>
using namespace std;

const int MAX = 102;
int N, M, vis[MAX];
vector<int> adj[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> q;
	q.push(1);
	vis[1] = 1;

	while(!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto &nxt : adj[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = 1;
		}
	}

	cout << count(vis, vis + N + 1, 1) - 1;
}