#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;

const int MAX = 502;
const int INF = 0x3f3f3f3f;

int N, M, S, D, dst[MAX];

priority_queue<P, vector<P>, greater<P>> pq;
vector<P> adj[MAX];
vector<int> parent[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(1) {
		for (int i = 0; i < MAX; i++) {
			adj[i].clear();
			parent[i].clear();
		}
		
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		cin >> S >> D;
		for (int i = 0; i < M; i++) {
			int u, v, p; cin >> u >> v >> p;
			adj[u].push_back({p, v});
		}

		// 첫번째 다익스트라
		fill(dst, dst + MAX, INF);
		
		
		pq.push({0, S});
		dst[S] = 0;

		while(!pq.empty()) {
			auto [w1, cur] = pq.top(); pq.pop();
			if (w1 != dst[cur]) continue;
			for (auto &it : adj[cur]) {
				auto [w2, nxt] = it;
				int w = w1 + w2;
				if (dst[nxt] >= w) { 
					if (dst[nxt] > w) {
						dst[nxt] = w;
						parent[nxt].clear();
						parent[nxt].push_back(cur);
						pq.push({w, nxt});
					} else {
						parent[nxt].push_back(cur);
					}
				}
			}
		}
		
		// 간선 지우기
		queue<int> q;
		q.push(D);
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			for (int u : parent[cur]) {
				for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
					if (it->second == cur) {
						q.push(u);
						it = adj[u].erase(it);
						break;
					}
				}
			}
		}
		
		// 두번째 다익스트라
		fill(dst, dst + MAX, INF);
		
		pq.push({0, S});
		dst[S] = 0;

		while(!pq.empty()) {
			auto [w1, cur] = pq.top(); pq.pop();
			if (w1 != dst[cur]) continue;
			for (auto &it : adj[cur]) {
				auto [w2, nxt] = it;
				int w = w1 + w2;
				if (dst[nxt] > w) { 
					dst[nxt] = w;
					pq.push({w, nxt});
				}
			}
		}

		cout << (dst[D] == INF ? -1 : dst[D]) << "\n";
	}
}
