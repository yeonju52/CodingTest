#include <iostream>
using namespace std;

int N;
int dp[3000001];
int route[3000001];

int main() {
	cin >> N;
	int idx = 1; // dp[0] = 0, dp[1] = 0;

	while (N != idx) {
		if (dp[idx * 3] == 0 || dp[idx * 3] > dp[idx] + 1) {
			dp[idx * 3] = dp[idx] + 1; route[idx * 3] = idx;
		}
		if (dp[idx * 2] == 0 || dp[idx * 2] > dp[idx] + 1) {
			dp[idx * 2] = dp[idx] + 1; route[idx * 2] = idx;
		}
		if (dp[idx + 1] == 0 || dp[idx + 1] > dp[idx] + 1) {
			dp[idx + 1] = dp[idx] + 1; route[idx + 1] = idx;
		}
		idx++;
	}
	cout << dp[N] << "\n";
	while (true) {
		cout << N << " ";
		if (N == 1) break;
		N = route[N];
	}
}