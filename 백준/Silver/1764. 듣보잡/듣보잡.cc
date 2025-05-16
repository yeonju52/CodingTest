#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_set<string> hsh;
set<string> dup;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        hsh.insert(s);
    }

    for (int j = 0; j < M; j++) {
        cin >> s;
        if(hsh.find(s) != hsh.end()) dup.insert(s);
    }
    
    cout << dup.size() << "\n";
    for (auto &ans : dup) cout << ans << "\n";
}