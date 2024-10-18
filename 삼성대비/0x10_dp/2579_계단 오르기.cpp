#include <iostream>
using namespace std;

int dp[301][3];
int stair[301];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;  cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}
	dp[1][0] = stair[1], dp[2][0] = stair[2], dp[2][1] = stair[1] + stair[2];
	for (int n = 3; n <= N; n++) {
		dp[n][0] += (max(dp[n - 2][0], dp[n - 2][1]) + stair[n]); // 1번 이하일 때: dp[3][0] = stair[3] + max(stair[1] + stair[0], stair[1])
		dp[n][1] += (dp[n - 1][0] + stair[n]); // 2번 연속: dp[3][1] = stair[3] + dp[2][0] = stair[3] + stair[2]
	}
	cout << max(dp[N][0], dp[N][1]);
}