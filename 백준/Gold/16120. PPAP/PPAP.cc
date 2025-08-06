#include <bits/stdc++.h>
using namespace std;

int main() {
	string str; cin >> str;
	string base = "PPAP";

	stack<char> st;
	for (auto &s : str) {
		st.push(s);
		if (st.size() >= 4) {
			string tmp;
			for (int i = 0; i < 4; i++) {
				tmp += st.top();
				st.pop();
			}
			reverse(tmp.begin(), tmp.end());
			if (tmp == base) st.push('P');
			else {
				for (auto &ns : tmp) {
					st.push(ns);
				}
			}
		}
	}

	cout << ((st.size() == 1 && st.top() == 'P') ? "PPAP" : "NP");
}
