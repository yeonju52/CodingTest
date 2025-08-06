#include <bits/stdc++.h>
using namespace std;

bool isNumber(const string &s) {
	for (const auto &c : s) {
		if (!isdigit(c)) return false;
	}
	return true;
}

int main() {
	string str;
	cin >> str;

	bool err = false;
	stack<string> st;
	for (char &c : str) {
		if (c == '(' || c == '[') st.push(string{c});
		else if (c == ')' || c == ']') {
			int cur = 0;	
			while(!st.empty() && isNumber(st.top())) {
				cur += stoi(st.top());
				st.pop();
			}
			if (!st.empty() && ((c == ')' && st.top() == "(") || (c == ']' && st.top() == "["))) {
				st.pop();
			}
			else {
				err = true;
				break;
			}
			cur = (cur == 0 ? 1 : cur);
			st.push(to_string(cur * (c == ')' ? 2 : 3)));
		}
		else {
			err = true;
			break;
		}
	}

	if(err || st.empty()) {
		cout << 0;
		return 0;
	}

	int ans = 0;
	while(!st.empty()) {
		if (!isNumber(st.top())) {
			cout << 0;
			return 0;
		}
		ans += stoi(st.top());
		st.pop();
	}
	cout << ans;
	return 0;
}
