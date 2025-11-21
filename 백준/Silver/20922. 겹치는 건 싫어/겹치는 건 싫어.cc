#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

vector<int> arr;
int cnt[100001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	//cin >> T;
	T = 1;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(cnt, 0, sizeof(cnt));
		int N, K; cin >> N >> K;
		for (int i = 0; i < N; i++) {
			int a; cin >> a;
			arr.push_back(a);
		}

		int l = 0, r = 0, ans = 0;
		while (r < N) {
			cnt[arr[r]]++;
			while (cnt[arr[r]] > K) {
				cnt[arr[l++]]--;
			}
			ans = max(ans, r - l + 1);
			r++;
		}
		cout << ans;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}