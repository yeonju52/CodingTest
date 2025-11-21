#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 100002;
int arr[MAX], sum[MAX];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	//cin >> T;
	T = 1;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
		cin >> N >> K;

		memset(arr, 0, sizeof(arr));
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		for (int i = 1; i <= N; i++) {
			sum[i] = sum[i - 1] + arr[i - 1];
		}
		
		int ans = -100 * MAX;
		for (int i = K; i <= N; i++) {
			ans = max(ans, sum[i] - sum[i - K]);
		}

		cout << ans;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}