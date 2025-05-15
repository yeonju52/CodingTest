#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;
string A, B;
int N, M, vis[MAX][MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;
    N = A.size(), M = B.size();
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (A[i - 1] == B[j - 1]) vis[i][j] += (vis[i - 1][j - 1] + 1);
            else vis[i][j] = max(vis[i - 1][j], vis[i][j - 1]);
        }
    }
    cout << vis[N][M] << "\n";
    if (vis[N][M] > 0) {
        string ans;
        int i = N, j = M;
        while (i > 0 && j > 0) {
            if (A[i - 1] == B[j - 1]) ans += A[i - 1], i--, j--;
            else if (vis[i - 1][j] > vis[i][j - 1]) i--;
            else j--;
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
}