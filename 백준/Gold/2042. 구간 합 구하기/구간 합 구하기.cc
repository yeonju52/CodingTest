#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
int N, M, K;

long long arr[MAX];
vector<long long> tree;

long long build(int i, int a, int b) {
    if (a == b) {
        tree[i] = arr[a];
        return tree[i]; // leaf node
    }

    int mid = (b - a) / 2 + a;
    long long l = build(i * 2, a, mid);
    long long r = build(i * 2 + 1, mid + 1, b);

    tree[i] = l + r;
    return tree[i]; // 부모 node
}

void update(int i, int a, int b, int idx, long long c) {
    if (a == b) {
        tree[i] = c; // 그냥 새 값으로 대입
        return;
    }

    int mid = (b - a) / 2 + a;
    if (idx <= mid) {
        update(i * 2, a, mid, idx, c);
    } else {
        update(i * 2 + 1, mid + 1, b, idx, c);
    }

    tree[i] = tree[i * 2] + tree[i * 2 + 1]; // 항상 자식 합으로 재계산
}

long long sum(int i, int a, int b, int st, int ed) {
    if (b < st || a > ed) {
        return 0;
    }
    if (a >= st && b <= ed) {
        return tree[i];
    }

    int mid = (b - a) / 2 + a;
    long long l = sum(i * 2, a, mid, st, ed);
    long long r = sum(i * 2 + 1, mid + 1, b, st, ed);
    
    return l + r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    tree.resize(N * 4, 0);
    build(1, 1, N);
    
    int q = M + K;
    while(q--) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 1, N, b, c);
            arr[b] = c;
        } else {
            cout << sum(1, 1, N, b, c) << "\n";
        }
    }
}
