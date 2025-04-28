#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    
    for (auto& oper : operations) {
        int cmd = oper[0], val = stoi(oper.substr(2));
        if (cmd == 'I') {
            ms.insert(val);
        }
        else {
            if (ms.empty()) continue;
            if (val == 1) ms.erase(--ms.end());
            else ms.erase(ms.begin());
        }
    }
    
    if (ms.empty()) return {0, 0};
    else return {*(--ms.end()), *ms.begin() };
    return answer;
}