#include <bits/stdc++.h>

using namespace std;

const int MAX = 10001;

unordered_map<string, multiset<string>> adj;
int N;
vector<string> res, ans;

bool dfs(string cur) {
    res.push_back(cur);
    if (N == res.size()) { ans = res; return true; }
    auto it = adj[cur].begin();
    while(it != adj[cur].end()) {
        auto nptr = it;
        string nxt = *it;
        it++;
        adj[cur].erase(nptr);
        if(dfs(nxt)) return true;
        adj[cur].insert(nxt);
    }
    res.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    int idx = 0;
    for (auto &t : tickets) {
        adj[t[0]].insert(t[1]);
    }
    
    N = tickets.size() + 1;
    dfs("ICN");
    return res;
}