#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<deque>

using namespace std;

deque<pair<int, int>> dq;

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
		dq.clear();

		int N, L;
		cin >> N >> L;
		for (int i = 0; i < N; i++) {
			int a; cin >> a;
			if (!dq.empty() && dq.front().second <= i - L) dq.pop_front();
			while (!dq.empty() && dq.back().first >= a) dq.pop_back();
			dq.push_back({ a, i });
			cout << dq.front().first << " ";
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}