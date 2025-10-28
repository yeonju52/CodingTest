#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> dp(K + 1, 0);
	dp[0] = 1;
	while (N--) {
		int v;  cin >> v;
		for (int j = v; j <= K; j++) {
			dp[j] += dp[j - v];
		}
	}
	cout << dp[K];
}