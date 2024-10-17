#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

int N;
unordered_set<string> info; // 이름 넣고

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N--) {
		string name, status;
		cin >> name >> status;
		if (status == "enter") info.insert(name);
		else info.erase(name);
	}
	vector<string> ans(info.begin(), info.end());
	sort(ans.begin(), ans.end(), greater<string>());
	for (string s : ans) cout << s << "\n";
}