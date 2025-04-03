#include <iostream>
using namespace std;

int dp[3000001];
int N;
void dfs(int idx, int cnt) {
	if (dp[idx] == 0) dp[idx] = cnt;
	if (idx >= N) return;
	
	dfs(idx * 3, cnt + 1);
	dfs(idx * 2, cnt + 1);
	dfs(idx + 1, cnt + 1);
}

int main() {
	dp[0] = 0, dp[1] = 0;
	cin >> N;
	int idx = 1;
	dfs(1, 0);
	cout << dp[N];
}