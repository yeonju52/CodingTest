#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<int> prefixSum(N + 1, 0);
    for (int i = 0; i < N; i++) {
        int v; cin >> v;
        prefixSum[i + 1] = prefixSum[i] + v;
    }

    while(M--) {
        int i, j; cin >> i >> j;
        cout << prefixSum[j] - prefixSum[i - 1] << "\n";
    }
}