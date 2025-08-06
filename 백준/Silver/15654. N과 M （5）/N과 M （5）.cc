#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr, vis;
vector<string> ans;

void dfs(int dep, string res) {
	if (dep == M) {
		ans.push_back(res);
		return ;
	}
	for (int i = 0; i < N; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		dfs(dep + 1, res + to_string(arr[i]) + " ");
		vis[i] = 0;
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

	vis.resize(N, 0);
	dfs(0, "");

	for (const auto &s : ans) cout << s << "\n";
}
