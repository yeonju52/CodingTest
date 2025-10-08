#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char d[4] = {'d', 'l', 'r', 'u'};

int N, M, K, EX, EY;
string ans;
bool found = false;

void dfs(int x, int y, string cur, int idx) {
    if (found) return;

    int dist = abs(EX - x) + abs(EY - y);
    if (dist > K - idx) return;
    if ((K - idx - dist) % 2 != 0) return;

    if (idx == K) {
        if (EX == x && EY == y) {
            ans = cur;
            found = true;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        dfs(nx, ny, cur + d[i], idx + 1);
        if (found) return;
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    N = n, M = m, K = k;
    x--, y--, r--, c--;
    EX = r, EY = c;
    ans = "impossible";
    dfs(x, y, "", 0);
    return ans;
}
