#include <bits/stdc++.h>
using namespace std;

int board[9][9];

vector<int> isOk(int x, int y) {
    vector<int> nine(10, 0);
    for (int i = 0; i < 9; i++) {
        nine[board[x][i]] = 1;
        nine[board[i][y]] = 1;
        nine[board[x/3*3 + i/3][y/3*3 + i%3]] = 1;
    }
    return nine;
}

vector<pair<int, int>> zero;
int N;

bool dfs(int cur) {
    if (cur == N) { 
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        return true;
    }
    int x = zero[cur].first, y = zero[cur].second;
    vector<int> nine = isOk(x, y);
    for (int k = 1; k <= 9; k++) {
        if(!nine[k]) {
            board[x][y] = k;
            if(dfs(cur + 1)) return true;;
        }
        board[x][y] = 0;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) zero.push_back({i, j});
        }
    }

    N = zero.size();
    dfs(0);
}