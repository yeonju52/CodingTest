	#include <bits/stdc++.h>
	using namespace std;

	using ll = long long;

	const int MAX = 10001, KMAX = 21;
	const ll INF = 0x3f3f3f3f3f3f3f3fLL;

	int N, M, K;

	ll dst[MAX][KMAX];
	vector<pair<ll, int>> adj[MAX];

	struct wvk {
		ll w;
		int v, k;
		bool operator>(const wvk &other) const {
			return w > other.w;
		}
	};

	priority_queue<wvk, vector<wvk>, greater<>> pq;

	int main() {
		ios::sync_with_stdio(0);
		cin.tie(0);

		cin >> N >> M >> K;
		for (int i = 0; i < M; i++) {
			int u, v; ll w; cin >> u >> v >> w;
			adj[u].push_back({w, v});
			adj[v].push_back({w, u});
		}
		
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= K; j++)
				dst[i][j] = INF;

		
		pq.push({0, 1, 0});
		dst[1][0] = 0;

		while(!pq.empty()) {
			auto [w1, cur, k] = pq.top(); pq.pop();
			if (dst[cur][k] != w1) continue;
			for (auto [w2, nxt] : adj[cur]) {
				if (dst[nxt][k] > w1 + w2) {
					dst[nxt][k] = w1 + w2;
					pq.push({w1 + w2, nxt, k});
				}
				if (k < K && dst[nxt][k + 1] > w1) {
					dst[nxt][k + 1] = w1;
					pq.push({w1, nxt, k + 1});
				}
			}
		}

		cout << *min_element(dst[N], dst[N] + K + 1);
	}
