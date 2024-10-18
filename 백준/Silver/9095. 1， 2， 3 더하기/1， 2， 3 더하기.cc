#define MAX 15
#include <iostream>
using namespace std;

int dp[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	int idx = 0;
	dp[1] = 1, dp[2] = 1, dp[3] = 1;
	while (++idx < 12) {
		dp[idx + 1] += dp[idx];
		dp[idx + 2] += dp[idx];
		dp[idx + 3] += dp[idx];
	}
	while (T--) {
		int n; cin >> n;
		cout << dp[n] << "\n";
	}
}