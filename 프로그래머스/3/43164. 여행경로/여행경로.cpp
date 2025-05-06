#include <bits/stdc++.h>

const int MAX = 10000;
using namespace std;

unordered_map<string, vector<string>> adj;
vector<string> ans;

bool dfs(string cur, int N) {
    if (ans.size() == N) return true;

    auto &nxts = adj[cur];
    for (int i = 0; i < nxts.size(); i++) {
        string next = nxts[i];
        ans.push_back(next);
        nxts.erase(nxts.begin() + i);
        if (dfs(next, N)) return true;
        nxts.insert(nxts.begin() + i, next);
        ans.pop_back();
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    for (auto &t : tickets) adj[t[0]].push_back(t[1]);
    
    for (auto &vec : adj) sort(vec.second.begin(), vec.second.end());
    
    ans.push_back("ICN");
    dfs("ICN", tickets.size() + 1);
    
    return ans;
}