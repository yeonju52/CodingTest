#include <bits/stdc++.h>

using namespace std;
const int MAX = 100001;
const int INF = 1000000001;

typedef long long ll;

int N, Q, arr[MAX];
pair<int, int> tree[MAX * 3];

void init(int ndx, int st, int ed);
pair<int, int> query(int ndx, int st, int ed, int L, int R);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    init(1, 1, N);
    
    while(Q--) {
        int l, r; cin >> l >> r;
        pair<int, int> ans = query(1, 1, N, l, r);
        cout << ans.first << " " << ans.second << "\n";
    }
}

pair<int, int> query(int ndx, int st, int ed, int L, int R) {
    if (st > R || ed < L) return {INF, 0};
    if (L <= st && ed <= R) return tree[ndx];

    pair<int, int> ll = query(ndx * 2, st, (st + ed) / 2, L, R);
    pair<int, int> rr = query(ndx * 2 + 1, (st + ed) / 2 + 1, ed, L, R);
    return { min(ll.first, rr.first), max(ll.second, rr.second) };
}

void init(int ndx, int st, int ed) {
    if (st == ed) { tree[ndx] = {arr[st], arr[st]}; return; }

    init(ndx * 2, st, (st + ed) / 2);
    init(ndx * 2 + 1, (st + ed) / 2 + 1, ed);
    tree[ndx] = { min(tree[ndx * 2].first, tree[ndx * 2 + 1].first), 
        max(tree[ndx * 2].second, tree[ndx * 2 + 1].second) };
}
