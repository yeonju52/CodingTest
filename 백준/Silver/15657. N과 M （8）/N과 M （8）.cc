#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr;

void dfs(int dep, int prev, string res) {
	if (dep == M) {
		cout << res << "\n";
		return ;
	}
	for (int i = 0; i < N; i++) {
		if (prev > arr[i]) continue;
		dfs(dep + 1, arr[i], res + to_string(arr[i]) + " ");
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		arr.push_back(n);
	}
	
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	dfs(0, -1, "");
}
