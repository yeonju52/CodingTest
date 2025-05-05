#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> p(1000001, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;
    if (p[v] < p[u]) swap(u, v); // v가 더 크다면
    if (p[v] == p[u]) p[u]--;
    p[v] = u;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while(M--) {
        int i, a, b;
        cin >> i >> a >> b;
        if (i == 0) {
            uni(a, b);
        }
        else {
            if (find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}