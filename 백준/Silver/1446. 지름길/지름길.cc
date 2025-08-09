#include <bits/stdc++.h>
using namespace std;

int N, D, dst[10001];
vector<pair<int, int>> spth[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		if (e > D) continue;
		spth[e].push_back({s, w});
	}

	dst[0] = 0;
	for (int i = 1; i <= D; i++) {
		dst[i] = min(i, dst[i - 1] + 1);
		for (auto [s, w] : spth[i]) {
			dst[i] = min(dst[i], dst[s] + w);
		}
	}
	
	cout << dst[D];
}
