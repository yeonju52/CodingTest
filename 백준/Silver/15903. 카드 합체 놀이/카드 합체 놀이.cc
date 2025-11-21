#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int MAX = 1002;
priority_queue<long long, vector<long long>, greater<>> pq;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	//cin >> T;
	T = 1;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int a; cin >> a;
			pq.push(a);
		}

		while (M-- && pq.size() > 1) {
			long long a = pq.top(); pq.pop();
			long long b = pq.top(); pq.pop();
			pq.push(a + b);
			pq.push(a + b);
		}

		long long ans = 0;
		while (!pq.empty()) {
			ans += pq.top(); pq.pop();
		}
		cout << ans;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}