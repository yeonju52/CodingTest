#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

int N, M;
unordered_map<string, int> info; // 이름 넣고
string infoidx[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> infoidx[i];
		info[infoidx[i]] = i;
	}
	while (M--) {
		string s; cin >> s;
		if (isdigit(s[0])) cout << infoidx[stoi(s)] << "\n";
		else cout << info[s] << "\n";
	}
}