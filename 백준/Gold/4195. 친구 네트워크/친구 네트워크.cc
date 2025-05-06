#include <bits/stdc++.h>
using namespace std;

int T, N;
vector<int> p(1000001, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

int uni(int u, int v) {
    u = find(u), v = find(v);
    
    if (u == v) return abs(p[u]);
    if (p[v] < p[u]) swap(v, u);
    p[u] += p[v];
    p[v] = u;
    return abs(p[u]);
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        fill(p.begin(), p.end(), -1);
        unordered_map<string, int> fridx;
        int idx = 0;
        
        cin >> N;
        while(N--) {
            string s1, s2; cin >> s1 >> s2;
            if(fridx.find(s1) == fridx.end()) fridx[s1] = idx++;
            if(fridx.find(s2) == fridx.end()) fridx[s2] = idx++;
            cout << uni(fridx[s1], fridx[s2]) << "\n";
        }
    }
    return 0;
}