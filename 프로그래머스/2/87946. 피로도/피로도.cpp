#include <string>
#include <vector>

using namespace std;

int N;
int answer = -1;

void dfs(int cur, vector<int> &vis, vector<vector<int>> &dungeons, int scr, int dep){
    vis[cur] = 1;
    answer = max(dep, answer);
    
    for(int nxt = 1; nxt < N; nxt++){
        if (!vis[nxt] && dungeons[nxt - 1][0] <= scr) dfs(nxt, vis, dungeons, scr - dungeons[nxt - 1][1], dep + 1);
    }
    vis[cur] = 0;
}

int solution(int k, vector<vector<int>> dungeons) {
    N = dungeons.size() + 1;
    vector<int> vis(N, 0);
    dfs(0, vis, dungeons, k, 0);
    
    return answer;
}