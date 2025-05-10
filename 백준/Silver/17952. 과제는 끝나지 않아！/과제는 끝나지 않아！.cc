#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
vector<int> scr, tml;
stack<int> st;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, cur = -1, ans = 0;
    
    cin >> T;
    while(T--) {
        int cmd, A = 0, T = 0;
        cin >> cmd;
        if (cmd == 1) {
            cin >> A >> T;
            if (cur >= 0) st.push(cur);
            scr.push_back(A), tml.push_back(T);
            cur = (int)scr.size() - 1;
        }
        if (cur < 0) continue;
        if (tml[cur] > 0) tml[cur]--;
        if (tml[cur] == 0) {
            ans += scr[cur];
            if (st.empty()) cur = -1;
            else cur = st.top(), st.pop();
        }
    }
    cout << ans;
}