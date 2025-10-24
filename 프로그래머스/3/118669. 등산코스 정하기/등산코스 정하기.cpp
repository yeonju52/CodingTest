#include <bits/stdc++.h>

using namespace std;

const int MAX = 50001, INF = 0x3f3f3f3f;

vector<pair<int, int>> adj[MAX]; // adj[u] = {w, v};
int dst[MAX];

unordered_set<int> G, S;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for (auto &cur : paths) {
        adj[cur[0]].push_back({cur[2], cur[1]});
        adj[cur[1]].push_back({cur[2], cur[0]});
    }
    for (auto &cur : gates) G.insert(cur);
    for (auto &cur : summits) S.insert(cur);
    
    fill(dst, dst + MAX, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (auto &g: gates) {
        dst[g] = 0;
        pq.push({dst[g], g});
    }
    while(!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (w != dst[u]) continue;
        if (S.find(u) != S.end()) continue;
        for (auto &[nw, v] : adj[u]) {
            if (G.find(v) != G.end()) continue;
            nw = max(w, nw);
            if (dst[v] > nw) {
                dst[v] = nw;
                pq.push({dst[v], v});
            }
        }
    }
    
    pair<int, int> ans = {INF, INF};
    for (auto &s : summits) ans = min(ans, {dst[s], s});
    return {ans.second, ans.first};
}