#include <bits/stdc++.h>

using namespace std;

const int MAX = 20001;
vector<int> adj[MAX];
int dist[MAX];

int solution(int n, vector<vector<int>> edge) {
    for (auto &e : edge) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    queue<int> q;
    q.push(1);
    dist[1] = 1;
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto &nxt : adj[cur]) {
            if(dist[nxt] > 0) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    int maxd = *max_element(dist + 1, dist + n + 1);
    return count(dist + 1, dist + n + 1, maxd);
}