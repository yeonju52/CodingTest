#include <bits/stdc++.h>

using namespace std;

int mx;
string str;
int vis[51];

bool dfs(string tar, string other) {
	if (other == "") {
		cout << tar << "\n";
		return true;
	}

	int cur = other[0] - '0';
	if (cur <= mx) {
		if (!vis[cur]) {
			vis[cur] = 1;
			if (dfs(tar + to_string(cur) + " ", other.substr(1))) return true;
			vis[cur] = 0;
		}
	}
	if (other.size() >= 2) {
		cur = cur * 10 + (other[1] - '0');
		if (cur <= mx) {
			if (!vis[cur]) {
				vis[cur] = 1;
				if (dfs(tar + to_string(cur) + " ", other.substr(2))) return true;
				vis[cur] = 0;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> str;
	
	mx = str.size();
	mx = (mx / 10 == 0 ? mx % 10 : (mx - 9) / 2 + 9);
	dfs("", str);
}
