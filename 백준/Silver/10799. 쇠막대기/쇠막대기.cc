#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	
	int res = 0, sz = str.size();
	stack<char> st;
	for (int i = 0; i < sz; i++) {
		if(str[i] == '(') st.push('(');
		else if (!st.empty()) {
			st.pop();
			if (i > 0 && str[i - 1] == '(') res += st.size();
			else res++;
		}
	}
	cout << res;
}
