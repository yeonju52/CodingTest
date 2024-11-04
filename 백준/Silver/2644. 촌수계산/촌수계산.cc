#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int N, M;
vector<int> family[102];
int dist[102];

int bfs(int st, int ed) {
	queue<int> Q;
	Q.push(st);
	dist[st] = 1;

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (cur == ed) {
			return dist[cur] - 1;
		}
		for (int next : family[cur]) {
			if (dist[next] > 0) continue;
			Q.push(next);
			dist[next] = dist[cur] + 1;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int  st, ed, x, y;
	cin >> N >> st >> ed >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		family[x].push_back(y);
		family[y].push_back(x);
	}

	memset(dist, 0, sizeof(dist));
	int answer = bfs(ed, st);
	memset(dist, 0, sizeof(dist));
	if (answer == -1) answer = bfs(st, ed);
	cout << answer;
}