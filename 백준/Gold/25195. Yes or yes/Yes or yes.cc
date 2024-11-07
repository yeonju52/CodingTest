#include <bits/stdc++.h>
using namespace std;

int N, M, S;
vector<int> graph[1000002];
int fan[1000002];
int vis[1000002];

bool dfs(int v){
    vis[v] = 1;
    if (fan[v]) return false;
    else if (graph[v].empty()) return true;
    for (int next : graph[v]){
        if (vis[next]) continue;
        if (dfs(next)) return true;
    }
    vis[v] = 0;
    return false;
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    cin >> S;
    for (int i = 0; i < S; i++){
        int s; cin >> s;
        fan[s] = 1;
    }
    if (!dfs(1)) cout << "Yes";
    else cout << "yes";
}