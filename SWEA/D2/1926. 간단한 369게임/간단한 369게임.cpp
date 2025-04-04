#include<iostream>
#include <cstdio>

using namespace std;

int	check369(int N);

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	//int test_case;
	//int T;
	//
	////freopen("input.txt", "r", stdin);
	//cin >> T;
	//
	//for (test_case = 1; test_case <= T; ++test_case)
	//{
		int N;
		cin >> N;

		for (int i = 1; i <= N; i++) {
			int sum = check369(i);
			if (sum == 0) cout << i;
			else {
				while (sum--) cout << '-';
			}
			cout << " ";
		}

	//}
	return 0;
}

int	check369(int N) {
	int sum = 0;

	while (N > 0) {
		int mod = N % 10;
		if (mod == 3 || mod == 6 || mod == 9) sum++;
		N /= 10;
	}

	return sum;
}