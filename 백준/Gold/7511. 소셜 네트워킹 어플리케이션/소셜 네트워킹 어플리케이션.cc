#include <bits/stdc++.h>
using namespace std;

int T, N, K, O;
vector<int> p(1000001, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (p[v] < p[u]) swap(v, u); // v가 크면 swap, 항상 u가 더 우선순위가 높게
    if (p[v] == p[u]) p[u]--;
    p[v] = u;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N;
        fill(p.begin(), p.end(), -1);
        cin >> K;
        while(K--) {
            int u, v; cin >> u >> v;
            uni(u, v);
        }
        cin >> O;
        cout << "Scenario " << i << ":\n";
        while(O--) {
            int u, v; cin >> u >> v;
            if (find(u) == find(v)) cout << "1\n";
            else cout << "0\n";
        }
        cout << "\n";
    }
}