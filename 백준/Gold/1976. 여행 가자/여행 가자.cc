#include <bits/stdc++.h>
using namespace std;

vector<int> p(200, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u), v = find(v);
    
    if (u == v) return false;
    if (p[v] < p[u]) swap(u, v);
    if (p[v] == p[u]) p[u]--;
    p[v] = u;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, road, dest; cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> road;
            if (i <= j || !road) continue;
            uni(i, j);
        }
    }

    cin >> dest;
    int nn = find(dest - 1), isOK = true;
    while(--M && isOK) {
        cin >> dest;
        if (nn != find(dest - 1)) isOK = false;
    }
    if (isOK) cout << "YES";
    else cout << "NO";
}