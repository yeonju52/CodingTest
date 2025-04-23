#include <iostream>
#include <vector>
using namespace std;

vector<int> board[4] = {
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0},
    {13, 16, 19, 25, 30, 35, 40, 0},
    {22, 24, 25, 30, 35, 40, 0},
    {28, 27, 26, 25, 30, 35, 40, 0}
};

vector<int> arr(10, 0);
pair<int, int> pos[5]; // 1 ~ 4
int ans = 0;

void play(int dep, int scr);
int change_dir(int i, int j);
bool canMove(int t, int idx);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    play(0, 0);
    cout << ans;
}

void play(int t, int scr) {
    if (t == 10) {
        ans = max(ans, scr);
        return ;
    }
    for (int i = 1; i <= 4; i++) {
        pair<int, int> backup = pos[i];
        if (!canMove(t, i)) continue;
        play(t + 1, scr + board[pos[i].first][pos[i].second]);
        pos[i] = backup;
    }
}

bool canMove(int t, int idx) {
    pair<int, int> cur = pos[idx];
    if (cur.second == (int)board[cur.first].size() - 1) return false; // 말이 도착지점이라면,
    
    // 다음 좌표 계산
    pair<int, int> nxt;
    int dir = change_dir(cur.first, cur.second);
    if (dir != 0) { // 방향 바뀜
        nxt = {dir, arr[t] - 1};
    }
    else {
        nxt = {cur.first, cur.second + arr[t]};
    }
    if (nxt.second >= (int)board[nxt.first].size() - 1) { // 도착점 확인
        pos[idx] = {nxt.first, (int)board[nxt.first].size() - 1};
        return true;
    }

    for (int i = 1; i <= 4; i++) { // 도착점 외 겹침 확인 (이동 가능한지 확인)
        if (i == idx) continue;
        pair<int, int> othr = pos[i];
        if (othr.first == nxt.first && othr.second == nxt.second) return false;
        // 다른 좌표 차원이지만, 겹치는 경우 (25, 30, 35, 40)
        // 40 (0 ~ 3)
        if (board[othr.first][othr.second] == 40 && board[nxt.first][nxt.second] == 40) return false;
        // 25, 30, 35 (1 ~ 3)
        if (othr.first != 0 && nxt.first != 0) {
            if (board[othr.first][othr.second] == 25 && board[nxt.first][nxt.second] == 25) return false;
            if (board[othr.first][othr.second] == 30 && board[nxt.first][nxt.second] == 30) return false;
            if (board[othr.first][othr.second] == 35 && board[nxt.first][nxt.second] == 35) return false;
        }
    }
    pos[idx] = nxt;
    return true;
}

int change_dir(int i, int j) {
    if (i != 0) return 0;
    if (j == 5 || j == 10 || j == 15) {
        return j / 5;
    }
    return 0;
}
