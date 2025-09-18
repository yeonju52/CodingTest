#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int MAX = 1000001;
int indegree[MAX], outdegree[MAX], vis[MAX];

vector<int> adj[MAX];

int find_shape(int st);

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);
    
    for (auto &edge : edges) {
        int a = edge[0], b = edge[1];
        outdegree[a]++, indegree[b]++;
        adj[a].push_back(b);
    }
    
    int org = -1;
    for (int i = 1; i < MAX && org == -1; i++) {
        if (outdegree[i] > 1 && indegree[i] == 0) org = i;
    }
    
    for (auto &edge : edges) {
        if (edge[0] == org) {
            indegree[edge[1]]--;
            if (!outdegree[edge[1]] && !indegree[edge[1]]) answer[2]++;
        }
    }
    // outdegree[org] = 0;
    
    answer[0] = org;
    vis[org] = 1;
    
    // memset(vis, 0, sizeof(vis));
    for (auto &st : edges) {
        if (vis[st[0]] == 0 && outdegree[st[0]]) answer[find_shape(st[0])]++;
    }
    
    answer[1] = outdegree[org] - answer[2] - answer[3];
    return answer;
}

int find_shape(int st) {
    queue<int> q;
    q.push(st);
    vis[st] = 1;
    
    bool isStick = false, isEight = false;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if (indegree[cur] == 0 && outdegree[cur] == 1) isStick = true;
        if (indegree[cur] == 2 && outdegree[cur] == 2) isEight = true;
        for (auto &nxt : adj[cur]) {
            if (vis[nxt] > 0) continue;
            q.push(nxt);
            vis[nxt] = vis[st] + 1;
        }
    }
    
    if (isStick) return 2;
    if (isEight) return 3;
    return 1;
}