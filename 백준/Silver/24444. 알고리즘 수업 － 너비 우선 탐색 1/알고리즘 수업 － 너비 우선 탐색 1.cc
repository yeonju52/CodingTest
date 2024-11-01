#define MAX 100002
#include <bits/stdc++.h>
using namespace std;

int N, M, R;
vector<int> ll[MAX];
int vis[MAX];

int main(){
    // 입력 및 초기화
    memset(vis, 0, sizeof(vis));
    cin >> N >> M >> R;
    for (int i = 0; i < M; i++){
        int u, v; cin >> u >> v;
        ll[u].push_back(v), ll[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) sort(ll[i].begin(), ll[i].end());
    // BFS
    int cnt = 0;
    queue<int> Q;
    vis[R] = ++cnt;
    Q.push(R);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for (int next : ll[cur]){
            if (vis[next] > 0) continue;
            vis[next] = ++cnt;
            Q.push(next);
        }
    }
    // 출력
    for (int i = 1; i <= N; i++) cout << vis[i] << "\n";
    return 0;
}