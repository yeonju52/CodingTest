#include <bits/stdc++.h>
using namespace std;

int N, cur, cnt;
vector<pair<int, int>> A;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e; cin >> s >> e;
		A.push_back({s, e});
	}
	
	sort(A.begin(), A.end());
	for (int i = 0; i <N; i++) {
		if (i == 0) cur = A[i].second;
		else {
			if (cur < A[i].first) { // 선을 이음
				cnt += (A[i].first - cur);
				cur = A[i].second;
			}
			else { // 새로운 선
				cur = max(A[i].second, cur);
			}
		}
	}
	cout << cur - A[0].first - cnt;
}
