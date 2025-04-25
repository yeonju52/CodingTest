#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> L;

    string s; cin >> s;
    int n; cin >> n;

    for (char i : s){
        L.push_back(i);
    }

    auto cur = L.end(); // 왼쪽이 기준
    while (n--){
        char cmd;
        cin >> cmd;
        if (cmd == 'P'){
            char add;
            cin >> add;
            L.insert(cur, add);
        }
        else if (cmd == 'L'){
            if (cur != L.begin()) cur--;
        }
        else if (cmd == 'D'){
            if (cur != L.end()) cur++;
        }
        else { // 'B'
            if (cur != L.begin()){
                cur--;
                cur = L.erase(cur);
            }
        }
    }

    for (char c: L) cout << c;
}