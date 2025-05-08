#include <bits/stdc++.h>

using namespace std;

int N, M;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> vis;

struct pos {
    int X, Y;
    bool operator!=(const pos &other) const {
        return !(X == other.X && Y == other.Y);
    }
    bool operator<(const pos &other) const {
        if (X == other.X) return Y < other.Y;
        return X < other.X;
    }
    static bool cmpY(const pos &a, const pos &b) {
        return a.Y < b.Y;
    }
};

void display(const vector<pos> &lst);
void displayList(const vector<vector<pos>> &arrList);
vector<pos> getUnit(int x, int y, vector<vector<int>> &board, int w, int v);
bool setPuzzle(vector<pos> &board, const vector<pos> &puzz);

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int ans = 0;
    N = game_board.size(), M = game_board[0].size();
    
    vector<vector<pos>> bList;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(game_board[i][j] == 0) bList.push_back(getUnit(i, j, game_board, 0, 1));
        }
    }
    
    vector<vector<pos>> pList;
    int idx = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(table[i][j] == 1) pList.push_back(getUnit(i, j, table, 1, ++idx));
        }
    }
    
    int llen = pList.size();
    vis.resize(llen, 0);
    for (auto &b : bList) {
        int blen = b.size();
        for (int i = 0; i < llen; i++) {
            if (vis[i]) continue;
            auto &p = pList[i];
            if (p.size() != blen) continue;
            if (setPuzzle(b, p)) {
                ans += blen;
                vis[i] = 1;
                break;
            }
        }
    }
    return ans;
}

bool setPuzzle(vector<pos> &board, const vector<pos> &puzz) {
    for (int r = 0; r < 4; r++) {
        int len = board.size();
        bool res = true;
        for (int i = 0; i < len; i++) {
            if (board[i] != puzz[i]) res = false;
        }
        if (res) return true;
        
        // 회전
        for (auto &b : board) swap(b.X, b.Y);
        int nY = max_element(board.begin(), board.end(), pos::cmpY)->Y;
        for (auto &b : board) b.Y = nY - b.Y;
        int minX = 51, minY = 51;
        for (auto &b : board) {
            minX = min(minX, b.X);
            minY = min(minY, b.Y);
        }
        for(auto &b : board) b.X -= minX, b.Y -= minY;
        sort(board.begin(), board.end());
    }
    return false;
}

vector<pos> getUnit(int x, int y, vector<vector<int>> &board, int w, int v) {
    vector<pos> res;
    queue<pos> q;
    q.push({x, y});
    board[x][y] = v;
    
    int minX = 51, minY = 51;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        res.push_back({cur.X, cur.Y});
        minX = min(cur.X, minX), minY = min(cur.Y, minY);
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i], ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == w) {
                q.push({nx, ny});
                board[nx][ny] = v;
            }
        }
    }
    
    for (auto &r : res) r.X -= minX, r.Y -= minY;
    sort(res.begin(), res.end());
    
    return res;
}

void display(const vector<pos> &lst) {
    for (auto &l : lst) cout << l.X << "," << l.Y << " ";
    cout << "\n";
}

void displayList(const vector<vector<pos>> &arrList) {
    for (auto &lst : arrList) {
        for (auto &l : lst) cout << l.X << "," << l.Y << " ";
        cout << "\n";
    }
}