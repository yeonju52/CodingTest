#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> mem(N, 0), cost(N, 0);
	for (int i = 0; i < N; i++) cin >> mem[i];
	for (int i = 0; i < N; i++) cin >> cost[i];

	int acc = accumulate(mem.begin(), mem.end(), 0);
	vector<int> dp(acc + 1, 0x3f3f3f3f);
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = acc; j >= mem[i]; j--) {
			dp[j] = min(dp[j], dp[j - mem[i]] + cost[i]);
		}
	}

	cout << *min_element(dp.begin() + K, dp.end());
}