#include <bits/stdc++.h>
using namespace std;

int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    priority_queue<int> sm;
    priority_queue<int, vector<int>, greater<>> lg;
    for (int i = 0; i < N; i++) {
        int v; cin >> v;
        if (sm.empty() || v <= sm.top()) sm.push(v);
        else lg.push(v);
        if (sm.size() < lg.size()) {
            sm.push(lg.top());
            lg.pop();
        }
        else if (sm.size() > lg.size() + 1) {
            lg.push(sm.top());
            sm.pop();
        }
        cout << sm.top() << "\n";
    }
}