#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	queue<int> q;
	
	int n; cin >> n;
	while(n != -1) {
		// 처리하고
		if (n == 0) {
			if (!q.empty()) q.pop();
		}
		else {
			if (q.size() < N) q.push(n);
		}
		// 입력받기
		cin >> n;
	}

	if (q.empty()) {
		cout << "empty";
		return 0;
	}
	
	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}
