#include <bits/stdc++.h>
using namespace std;

#define w first
#define v second
typedef pair<int, int> pii;

const int MAX = 2001;
const int INF = MAX * 1000;

int tc, N, M, T, s, g, h, a, b, d, t, ghw;
int dst[MAX];

vector<pii> adj[MAX], tar; // { dist, v }
set<int> ans;

void dikjstra(int s);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while(tc--) {
        for (int i = 0; i < MAX; i++) adj[i].clear();
        tar.clear();
        ans.clear();
        ghw = INF;

        cin >> N >> M >> T
            >> s >> g >> h;
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> d;
            adj[a].push_back({d, b});
            adj[b].push_back({d, a});
            if ((a == g && b == h) || (a == h && b == g)) ghw = min(ghw, d);
        }
        for (int i = 0; i < T; i++) {
            cin >> t;
            tar.push_back({0, t}); // 목적지 후보
        }
        
        // 최단경로 구하기 (목적지 후보 tar: dist 값 갱신)
        dikjstra(s);
        int s2g = dst[g], s2h = dst[h];
        for (auto &cur : tar) cur.w = dst[cur.v];

        // (g, h)를 포함한 경로의 길이 == 최단경로 : 정답
        dikjstra(g);
        for (auto &cur : tar) if (s2h + ghw + dst[cur.v] == cur.w) ans.insert(cur.v);
        
        dikjstra(h);
        for (auto &cur : tar) if (s2g + ghw + dst[cur.v] == cur.w) ans.insert(cur.v);
        
        for (auto &a : ans) cout << a << " ";
        cout << "\n";
    }
}

void dikjstra(int s) {
    fill(dst, dst + N + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dst[s] = 0;

    while(!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (w != dst[u]) continue;
        for (auto &nxt : adj[u]) {
            int v = nxt.v, nw = nxt.w;
            if (dst[v] > dst[u] + nw) {
                dst[v] = dst[u] + nw;
                pq.push({dst[v], v});
            }
        }
    }
    return ;
}