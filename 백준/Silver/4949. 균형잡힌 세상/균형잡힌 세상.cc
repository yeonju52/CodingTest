#include<bits/stdc++.h>
using namespace std;

string str;
int main() {
    getline(cin, str);
    while(str != ".") {
        stack<char> st;
        bool ans = true;
        for (auto &s : str) {
            if (s == '(') st.push('(');
            else if (s == '[') st.push('[');
            else if (s == ')') {
                if (!st.empty() && st.top() == '(') st.pop();
                else ans = false;
            }
            else if (s == ']') {
                if (!st.empty() && st.top() == '[') st.pop();
                else ans = false;
            }
        }
        cout << ((ans && st.empty()) ? "yes\n" : "no\n");
        getline(cin, str);
    }
}