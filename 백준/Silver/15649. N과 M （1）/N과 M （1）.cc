#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
void dfs(vector<int> visited, string arr) {
	if (arr.length() == M) {
		for (int i = 0; i < arr.length(); i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			arr += (to_string(i));
			visited[i] = 1;
			dfs(visited, arr);
			arr.pop_back();
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	vector<int> visited(N + 1, 0);
	dfs(visited, "");
}