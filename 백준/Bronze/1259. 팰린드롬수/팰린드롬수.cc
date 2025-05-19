#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> st;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> s) {
        if (s == "0") break;
        int l = 0, r = s.size() - 1;
        bool isPan = true;
        while(l < r && isPan) {
            if (s[l] == s[r]) l++, r--;
            else isPan = false;
        }
        cout << (isPan ? "yes\n" : "no\n");
    }
    return 0;
}