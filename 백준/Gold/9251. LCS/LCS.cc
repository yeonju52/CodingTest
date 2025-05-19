#include <bits/stdc++.h>
using namespace std;

string a, b;
int N, M, lcs[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    N = a.size(), M = b.size();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
            if (a[i - 1] == b[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
        }
    }
    cout << lcs[N][M];
    return 0;
}