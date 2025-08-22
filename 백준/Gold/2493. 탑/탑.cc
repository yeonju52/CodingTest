#include <bits/stdc++.h>
using namespace std;

int N;
stack<pair<int, int>> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int v; cin >> v;
		
		while(!st.empty() && st.top().first < v) st.pop();

		if (st.empty()) {
			cout << "0 ";
		}
		else {
			cout << st.top().second << " ";
		}
		st.push({v, i});

	}
}