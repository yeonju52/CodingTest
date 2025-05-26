#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;
const int INF = 0x3f3f3f3f;

int N, brt, arr[MAX], vis[MAX];
vector<int> adj[MAX];

int bfs(int s);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < N; i++) {
        int M; cin >> M;
        while(M--) {
            int node; cin >> node;
            adj[i].push_back(node - 1);
        }
    }

    brt = (1 << N);
    // 1-based index -> 0-based index
    int ans = INF;

    while(--brt) {
        memset(vis, 0, sizeof(vis));
        // 1인 구역 확인
        int i = 0;
        for (; i < N; i++) {
            if (((brt >> i) & 1)) break;
        }
        int c0 = bfs(i);
        if (find(vis, vis + N, 0) == vis + N) continue; // 구역이 안 나뉘는 경우, 불가능한 방법
        
        // 0인 구역 확인
        for (i = 0; i < N; i++) {
            if (!((brt >> i) & 1)) break;
        }
        int c1 = bfs(i);
        if (find(vis, vis + N, 0) != vis + N) continue; // 모두 탐색했는데, 방문 안 한 경우, 불가능한 방법

        ans = min(ans, abs(c0 - c1));
    }
    if (ans == INF) cout << -1;
    else cout << ans;
}

int bfs(int s) {
    queue<int> q;
    int cc = (brt >> s) & 1; // 1이면 1, 0이면 0
    q.push(s);
    vis[s] = 1;
    int sum = 0;

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        sum += arr[cur];
        for (auto &nxt : adj[cur]) {
            if (vis[nxt]) continue;
            if (((brt >> nxt) & 1) ^ cc) continue; // 다른 구역일 때
            // (주의) &1 필수!!! 이거 안하면 오른쪽 시프트한 전체 값과 cc와 비교하게 됨. 내 의도는 마지막 비트만 비교하는 것
            q.push(nxt);
            vis[nxt] = 1;
        }
    }
    return sum;
}