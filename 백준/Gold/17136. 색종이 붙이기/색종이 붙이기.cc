#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> P;
int board[10][10], vis[10][10], backup[10][10];

bool isOK(int x, int y, int s) {
    for (int i = x; i < x + s; i++) {
        for (int j = y; j < y + s; j++) {
            if (i >= 10 || j >= 10) return false;
            if (!board[i][j] || vis[i][j]) return false;
        }
    }
    return true;
}

int ans = 101;
void bt(vector<P> &paper, vector<int> &cnt) {
    if (paper.empty()) {
        int total = 0;
        for (auto &c : cnt) total += (5 - c);
        ans = min(ans, total);
        return;
    }

    for (auto &p : paper) {
        int x = p.first, y = p.second;
        if (!board[x][y] || vis[x][y]) continue;
        for (int s = 5; s > 0; s--) {
            if (cnt[s - 1] == 0) continue;
            if (isOK(x, y, s)) {
                for (int i = x; i < x + s; i++) {
                    for (int j = y; j < y + s; j++) {
                        vis[i][j] = 1;
                    }
                }
                cnt[s - 1]--;
                vector<P> np;
                for (auto &p : paper) {
                    if (!vis[p.first][p.second]) np.push_back(p);
                }

                bt(np, cnt);
                cnt[s - 1]++;
                for (int i = x; i < x + s; i++) {
                    for (int j = y; j < y + s; j++) {
                        vis[i][j] = 0;
                    }
                }
                // return; // 이거 오답
            }
        }
        return; // 좌표 하나만 탐색하고 return, 없으면 무한루프
    }
}

int main() {
    vector<P> paper;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
            if (board[i][j]) paper.push_back({i ,j});
        }
    }
    
    vector<int> cnt = {5, 5, 5, 5, 5};
    bt(paper, cnt);
    if (ans == 101) ans = -1;
    cout << ans;
}