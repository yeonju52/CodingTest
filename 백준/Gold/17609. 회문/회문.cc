#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;

bool psudoR(string &s, int L, int R) {
    while (L < R) {
        if (s[L] != s[R]) return false;   
        L++, R--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    while(N--) {
        string s; cin >> s;
        int L = 0, R = (int)s.size() - 1;
        int ans = 0;
        while (L < R) {
            if (s[L] != s[R]) {
                if (psudoR(s, L + 1, R) || psudoR(s, L, R - 1)) ans = 1;
                else ans = 2;
                break;
            }
            L++, R--;
        }
        cout << ans << "\n";
    }
}