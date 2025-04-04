#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 10;
int N, M;
long long guitar[MAX];

int bit_cnt(long long x);

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s, yn;
		cin >> s >> yn;
		for (int j = 0; j < M; j++) {
			if (yn[j] == 'Y') {
				guitar[i] |= (1LL << (M - 1 - j));
			}
		}
	}

	pair<int, int> answer = { 0, N }; // 연주 곡 수, 최소 기타 수;

	for (int c = 1; c < (1 << N); c++) {
		long long comb = 0;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (c & (1 << i)) {
				comb |= guitar[i];
				cnt++;
			}
		}
		int song_cnt = bit_cnt(comb);
		int guitar_cnt = bit_cnt(c);

		if (answer.first < song_cnt) {
			answer = { song_cnt, guitar_cnt };
		}
		else if (answer.first == song_cnt) {
			answer.second = min(answer.second, guitar_cnt);
		}

	}

	if (answer.first == 0) cout << -1 << "\n";
	else cout << answer.second << "\n";
}

int bit_cnt(long long x) {
	int ret = 0;
	for (int i = 0; i < max(N, M); i++) {
		ret += (x >> i) & 1;
	}
	return ret;
}