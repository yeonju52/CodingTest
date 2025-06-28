#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, V, p[500001];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u), v= find(v);
    if (u == v) return true;
    if (p[u] < p[v]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> V;
    fill(p, p + N + 1, -1);
    int ans = 0;
    while(++ans <= V) {
        int u, v; cin >> u >> v;
        if (uni(u, v)) break;
    }
    if (ans > V) cout << 0;
    else cout << ans;
    return 0;
}