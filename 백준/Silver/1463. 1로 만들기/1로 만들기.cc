#include <iostream>
using namespace std;

int dp[3000001];
int N;
//void dfs(int idx, int cnt) {
//	if (dp[idx] == 0) dp[idx] = cnt;
//	if (idx >= N) return;
//	
//	dfs(idx * 3, cnt + 1);
//	dfs(idx * 2, cnt + 1);
//	dfs(idx + 1, cnt + 1);
//}

int main() {
	cin >> N;
	//dfs(1, 0); // 시간초과, dp[3000001]으로 변경 필요
	int idx = 1; // dp[0] = 0, dp[1] = 0;
	while (N != idx) {
		if (dp[idx * 3] == 0 || dp[idx * 3] > dp[idx] + 1) dp[idx * 3] = dp[idx] + 1;
		if (dp[idx * 2] == 0 || dp[idx * 2] > dp[idx] + 1) dp[idx * 2] = dp[idx] + 1;
		if (dp[idx + 1] == 0 || dp[idx + 1] > dp[idx] + 1) dp[idx + 1] = dp[idx] + 1;
		idx++;
	}
	cout << dp[N];
}