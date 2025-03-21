#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<int> graph[101];
int vis[101];

int dfs(int v, int cnt) {
    vis[v] = 1;
    
    int len = graph[v].size();
    for (int i = 0; i < len; i++){
        if (!vis[graph[v][i]]) cnt += dfs(graph[v][i], 1);
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 111;
    
    // 인접 리스트 생성
    for (auto w : wires) {
        int v1 = w[0], v2 = w[1];
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    // 하나씩 삭제하면서 완전탐색
    for (auto w : wires) {
        memset(vis, 0, sizeof(vis));
        vis[w[0]] = 1;
        vis[w[1]] = 1;
        
        int val1 = dfs(w[0], 1), val2 = dfs(w[1], 1);
        answer = min(abs(val1 - val2), answer);
    }
    return answer;
}