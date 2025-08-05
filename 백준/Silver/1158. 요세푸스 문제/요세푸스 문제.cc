#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	queue<int> q;
	for (int i = 1; i <= N; i++) q.push(i);

	
	while(!q.empty()) {
		for (int i = 1; i < K; i++) {
			q.push(q.front());
			q.pop(); // 실제 순서는 빼는게 먼저긴 함
		}
		ans.push_back(q.front());
		q.pop();
	}
	cout << "<";
	for (int i = 0; i < N - 1; i++) cout << ans[i] << ", ";
	cout << ans[N - 1] << ">";
}
