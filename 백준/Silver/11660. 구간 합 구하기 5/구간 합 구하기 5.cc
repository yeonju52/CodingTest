#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<vector<int>> prefixSum(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int v; cin >> v;
            prefixSum[i + 1][j + 1] = prefixSum[i + 1][j] + prefixSum[i][j + 1] 
                                        - prefixSum[i][j] + v;
        }
    }

    while(M--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << prefixSum[x2][y2] - prefixSum[x2][y1 - 1] - prefixSum[x1 - 1][y2] + prefixSum[x1 - 1][y1 - 1] << "\n";
    }
}