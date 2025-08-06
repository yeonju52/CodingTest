#include <bits/stdc++.h>

using namespace std;

int N, P;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> P;
	vector<stack<int>> guitar(6);

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int l, p; cin >> l >> p;
		l--;
		while(!guitar[l].empty() && guitar[l].top() > p) {
			guitar[l].pop();
			ans++;
		}
		if (!guitar[l].empty() && guitar[l].top() == p) continue;
		guitar[l].push(p);
		ans++;
	}
	cout << ans;
}
