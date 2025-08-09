#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;

const int MAX = 1002;

int N, M, K;

priority_queue<int> dst[MAX]; // 최대힙
vector<P> adj[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({c, b});
	}

	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({0, 1});
	dst[1].push(0);

	while(!pq.empty()) {
		auto [w, u] = pq.top(); pq.pop();
		for (auto &nxt : adj[u]) {
			auto [nw, v] = nxt;
			nw += w;
			if (dst[v].size() < K) {
				dst[v].push(nw);
				pq.push({nw, v});
			}
			else if (dst[v].top() > nw) { // K개 유지하기
				dst[v].pop();
				dst[v].push(nw);
				pq.push({nw, v});
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (dst[i].size() < K) cout << "-1\n";
		else cout << dst[i].top() << "\n";
	}
}
