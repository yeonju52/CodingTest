#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> board;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    board.resize(N, 0);
    for (int i = 0; i < N; i++) cin >> board[i];

    sort(board.begin(), board.end());
    while(M--) {
        int v; cin >> v;
        auto iter = lower_bound(board.begin(), board.end(), v);
        // auto iter = find(board.begin(), board.end(), v);
        if (iter == board.end() || *iter != v) cout << -1 << "\n";
        else cout << iter - board.begin() << "\n";
    }
}