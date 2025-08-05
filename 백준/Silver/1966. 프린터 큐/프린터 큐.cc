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
		vector<int> pri;
		for (int i = 0; i < N; i++) {
			int n; cin >> n;
			q.push({n, i}); pri.push_back(n);
		}

		sort(pri.begin(), pri.end(), greater<int>());
		for (int i = 0; i < N; i++) {
			while(q.front().first != pri[i]) {
				q.push(q.front());
				q.pop();
			}
			if (q.front().second == M) {
				cout << i + 1 << "\n";
				break;
			}
			q.pop();
		}
	}
}
