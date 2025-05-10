#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
int N, board[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> board[i];

    cout << *min_element(board, board + N) << " " << *max_element(board, board+ N);
}