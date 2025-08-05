#include <bits/stdc++.h>
using namespace std;

int T, N, M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> N >> M;
		queue<pair<int, int>> q;
		priority_queue<int> maxH;
		for (int i = 0; i < N; i++) {
			int n; cin >> n;
			q.push({n, i}); maxH.push(n);
		}

		int res = 0;
		while(!q.empty()) {
			auto cur = q.front();
			if (cur.first == maxH.top()) {
				q.pop(); maxH.pop();
				res++;
				if (cur.second == M) break;
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
		cout << res << "\n";
	}
}
