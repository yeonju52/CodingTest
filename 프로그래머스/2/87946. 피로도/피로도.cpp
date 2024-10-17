#define INF 1000000000
#include <bits/stdc++.h>

using namespace std;

int N, maxi;
vector<vector<int>> dun;

void comb(int cur, int k, vector<int> vis){
    if (cur > N) return;
    maxi = max(maxi, cur);

    for (int i = 1; i <= N; i++){
        if (vis[i]) continue;
        if (k < dun[i - 1][0]) continue;
        vis[i] = 1;
        comb(cur + 1, k - dun[i - 1][1], vis);
        vis[i] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    N = dungeons.size();
    dun = dungeons;
    vector<int> empty(9, 0);
    comb(0, k, empty);

    answer = maxi;
    return answer;
}