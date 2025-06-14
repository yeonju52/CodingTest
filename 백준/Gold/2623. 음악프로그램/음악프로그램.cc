#include <bits/stdc++.h>
using namespace std;

int N, S;

vector<vector<int>> arr;
vector<int> deg, ans;

int main() {
    cin >> N >> S;
    arr.resize(N + 1), deg.resize(N + 1);
    for (int i = 0; i < S; i++) {
        int s; cin >> s;
        int prev = -1, cur;
        while(s--) {
            cin >> cur;
            if (prev != -1) {
                arr[prev].push_back(cur);
                deg[cur]++;
            }
            prev = cur;
        }
    }

    // indegree == 0을 만들자 -> deg 벡터
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if(deg[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for (auto &nxt : arr[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }

    if (ans.size() != N) cout << "0\n";
    else {
        for (auto& a : ans) cout << a << "\n";
    }
    return 0;
}