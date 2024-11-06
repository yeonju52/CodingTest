#define X first
#define Y second
#include <bits/stdc++.h>

using namespace std;

int N, M, K, st;
vector<int> road[300002];
int dist[300002];
vector<int> answer;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K >> st;
    for (int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        road[x].push_back(y);
    }

    queue<int> Q;
    Q.push(st);
    dist[st] = 1;

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if (dist[cur] == K + 1) answer.push_back(cur);
        for (int next : road[cur]){
            if (dist[next] > 0) continue;
            Q.push(next);
            dist[next] = dist[cur] + 1;
        }
    }
    if (answer.empty()) {
        cout << -1 << "\n";
        return 0;
    }
    sort(answer.begin(), answer.end());
    for (int ans : answer){
        cout << ans << "\n";
    }
}