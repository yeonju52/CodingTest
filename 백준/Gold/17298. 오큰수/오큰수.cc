#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N; cin >> N;
	vector<int> arr(N, 0), ans(N, -1);
	for(int i = 0; i < N; i++) cin >> arr[i];

	stack<int> st;
	for(int i = N - 1; i >= 0; i--) {
		while(!st.empty() && st.top() <= arr[i]) {
			st.pop();
		}
		if (!st.empty()) ans[i] = st.top();
		st.push(arr[i]);
	}

	for (auto &n : ans) cout << n << " ";
	return 0;
}
