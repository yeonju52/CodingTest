#include <bits/stdc++.h>
using namespace std;

int K;
deque<int> dq[4];
int action[4];

void roll() {
	for (int i = 0; i < 4; i++) {
		deque<int> &wh = dq[i];
		if (action[i] == 1) {
			wh.push_front(wh.back());
			wh.pop_back();
		}
		else if (action[i] == -1) {
			wh.push_back(wh.front());
			wh.pop_front();
		}
		// else -> action[i] == 0
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			char c; cin >> c;
			dq[i].push_back(c - '0');
		}
	}

	cin >> K;
	while(K--) {
		int idx, cw;
		cin >> idx >> cw;

		memset(action, 0, sizeof(action));
		action[--idx] = cw;
		for (int i = 1; i < 4; i++) {
			int nxt = idx + i, prev = idx - i;
			if (nxt < 4 && action[nxt - 1] != 0) {
				if (dq[nxt - 1][2] != dq[nxt][6]) action[nxt] = (action[nxt - 1] == 1 ? -1 : 1);
			}
			if (prev >= 0 && action[prev + 1] != 0) {
				if (dq[prev][2] != dq[prev + 1][6]) action[prev] = (action[prev + 1] == 1 ? -1 : 1);
			}
		}

		roll();
	}

	int ans = 0;
	if (dq[0][0]) ans += 1;
	if (dq[1][0]) ans += 2;
	if (dq[2][0]) ans += 4;
	if (dq[3][0]) ans += 8;
	cout << ans;
}
