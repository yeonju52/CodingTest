#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int RGB[1002][3] = { 0, 0, 0 };
int dp[1002][3];
int brute[6][2] = { {1, 0}, {2, 0}, {0, 1}, {2, 1}, {0, 2}, {1, 2} };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;  cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
	}
	memcpy(dp[0], RGB[0], sizeof(RGB[0])); // *min_element(RGB[0], RGB[0] + 3); // cout << dp[0];

	for (int idx = 1; idx < N; idx++) { // RGB RBG GBR GRB BGR BRG = 3C2 3 * 2 * 2 * 2 ... = 3 * 2^n-1 = 3 * 2 ^ 1000 - 1 경우의 수가 넘 크다. -> DP..?
		for (int c = 0; c < 3; c++) {
			dp[idx][c] = min(dp[idx - 1][(c + 1) % 3], dp[idx - 1][(c + 2) % 3]) + RGB[idx][c];
		}
	}
	cout << *min_element(dp[N - 1], dp[N - 1] + 3);
}