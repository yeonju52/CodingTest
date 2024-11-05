#define X first
#define Y second
#include <bits/stdc++.h>
using namespace std;

int N, l;
int board[302][302];
pair<int, int> start, target;

int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while(N--){
        memset(board, 0, sizeof(board));
        cin >> l;
        int x, y;
        cin >> x >> y;
        start = {x, y};
        cin >> x >> y;
        target = {x, y};

        queue<pair<int, int>> Q;
        Q.push(start);
        board[start.X][start.Y] = 1;

        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            if (cur == target) break;
            for (int i = 0; i < 8; i++){
                int nx = cur.X + dx[i], ny = cur.Y + dy[i];
                if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if (board[nx][ny] > 0) continue;
                Q.push({nx, ny});
                board[nx][ny] = board[cur.X][cur.Y] + 1;
            }
        }
        cout << board[target.X][target.Y] - 1 << "\n";
    }

}