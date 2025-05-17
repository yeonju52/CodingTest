#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;
vector<int> adj[MAX], rev[MAX];
int vis[MAX];

void bfs(int i, vector<int> (&arr)[MAX]) {
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto &nxt : arr[cur]) {
            if(vis[nxt] > 0) continue;
            q.push(nxt);
            vis[nxt] = 1;
        }
    }
}
int solution(int n, vector<vector<int>> results) {
    int ans = 0;
    for (auto &res : results) adj[res[0]].push_back(res[1]), rev[res[1]].push_back(res[0]);
    
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        bfs(i, adj);
        bfs(i, rev);
        if (count(vis + 1, vis + n + 1, 1) == n) ans++;
    }
    return ans;
}