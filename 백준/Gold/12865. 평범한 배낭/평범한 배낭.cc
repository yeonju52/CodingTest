#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<pair<int, int>> arr;

int dp[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int w, v; cin >> w >> v;
		arr.push_back({w, v});
	}
	dp[0] = 0;
	for (auto&[w, v] : arr) {
		for (int j = K; j >= w; j--) dp[j] = max(dp[j], dp[j - w] + v);
	}
	cout << dp[K];
	return 0;
}
