#include <bits/stdc++.h>

using namespace std;

const int MAX = 2500;
int p[MAX];

unordered_map<int, string> cell;

int mapping(int r, int c) { return (--r * 50 + --c); }

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    
    p[v] = u;
    
    if (!cell.count(u) && cell.count(v)) cell[u] = cell[v];
    cell.erase(v);
    
    return true;
}

void ununi(int v) {
    int u = find(v);
    string val = "";
    if (cell.count(u)) val = cell[u];
    cell.erase(u);
    
    vector<int> child;
    for (int i = 0; i < MAX; i++) {
        if (find(i) == u) child.push_back(i);
    }
    for (int x : child) p[x] = -1;
    
    if (!val.empty()) cell[v] = val; 
    return ;
}

vector<string> solution(vector<string> commands) {
    vector<string> ans;
    for (int i = 0; i < MAX; i++) {
        p[i] = -1;
    }
    
    for (auto &cur : commands) {
        stringstream ss(cur);
        vector<string> cmd;
        string v;
        while(ss >> v) cmd.push_back(v);
        
        if (cmd[0] == "UPDATE") {
            if (cmd.size() == 4) {
                int r = stoi(cmd[1]), c = stoi(cmd[2]);
                string val = cmd[3];
                cell[find(mapping(r, c))] = val;
            }
            else {
                string val1 = cmd[1], val2 = cmd[2];
                for (auto &[k, v] : cell) {
                    if (v == val1) v = val2;
                }
            }
        }
        else if (cmd[0] == "MERGE") {
            uni(mapping(stoi(cmd[1]), stoi(cmd[2])), 
                mapping(stoi(cmd[3]), stoi(cmd[4])));
        }
        else if (cmd[0] == "UNMERGE") {
            ununi(mapping(stoi(cmd[1]), stoi(cmd[2])));
        }
        else if (cmd[0] == "PRINT") {
            int idx = find(mapping(stoi(cmd[1]), stoi(cmd[2])));
            string val = (cell.count(idx) ? cell[idx] : "EMPTY");
            ans.push_back(val);
        }
    }
    
    // for (auto &[k, v] : cell) {
    //     cout << k << " " << v << "\n";
    // }
    return ans;
}