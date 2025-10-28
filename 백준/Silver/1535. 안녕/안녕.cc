#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> HP(N, 0), joy(N, 0);
	for (int i = 0; i < N; i++) cin >> HP[i];
	for (int i = 0; i < N; i++) cin >> joy[i];

	vector<int> dp(101, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 100; j > HP[i]; j--) {
			dp[j] = max(dp[j], dp[j - HP[i]] + joy[i]);
		}
	}
	cout << dp[100];
}