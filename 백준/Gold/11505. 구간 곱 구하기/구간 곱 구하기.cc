#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
const int INF = 1000000007;
typedef long long ll;

int N, M, K;
int arr[MAX];
ll tree[MAX * 3];

void init(int ndx, int l, int r);
void update(int ndx, int l, int r, int idx, int val); // update 구간, 포함되는 경우만
ll query(int ndx, int l, int r, int st, int ed);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    init(1, 1, N);
    
    int Q = M + K;
    while(Q--) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            update(1, 1, N, b, c);
        }
        else {
            cout << query(1, 1, N, b, c) << "\n";
        }
    }
}

ll query(int ndx, int l, int r, int st, int ed) {
    if (ed < l || st > r) return 1;
    if (st <= l && r <= ed) return tree[ndx];

    return (query(ndx * 2, l, (l + r) / 2, st, ed) * query(ndx * 2 + 1, (l + r) / 2 + 1, r, st, ed)) % INF;
}

void update(int ndx, int l, int r, int idx, int val) {
    if (idx < l || idx > r) return ;
    if (l == r) { tree[ndx] = val; return; }
    
    update(ndx * 2, l, (l + r) / 2, idx, val);
    update(ndx * 2 + 1, (l + r) / 2 + 1, r, idx, val);
    tree[ndx] = (tree[ndx * 2] * tree[ndx * 2 + 1]) % INF;
}

void init(int ndx, int l, int r) {
    if (l == r) { tree[ndx] = arr[l]; return; }

    init(ndx * 2, l, (l + r) / 2);
    init(ndx * 2 + 1, (l + r) / 2 + 1, r);
    tree[ndx] = (tree[ndx * 2] * tree[ndx * 2 + 1]) % INF;
}
