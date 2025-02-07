#include <bits/stdc++.h>
using namespace std;

int to_sec(string t) {
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int len = to_sec(video_len), cur = to_sec(pos), st = to_sec(op_start), ed = to_sec(op_end);
    
    for (auto cmd : commands) {
        if (cur >= st && cur <= ed) cur = ed;
        int nxt = cur + (cmd == "next" ? 10 : -10);
        if (nxt >= st && nxt <= ed) nxt = ed;
        cur = max(0, min(nxt, len));
    }
    
    return (cur / 60 < 10 ? "0" : "") + to_string(cur / 60) + ":" +
           (cur % 60 < 10 ? "0" : "") + to_string(cur % 60);
}