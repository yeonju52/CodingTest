#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string ans = "";
    for (auto &cur : new_id) {
        if (cur >= 'A' && cur <= 'Z') cur += 32;
        if (isalnum(cur) || cur == '-' || cur == '_' || cur == '.') ans += cur;
    }
    
    new_id = ans; ans = "";
    for (char cur : new_id) {
        if (cur == '.' && !ans.empty() && ans.back() == '.') continue;
        ans.push_back(cur);
    }
    if (!ans.empty() && ans.front() == '.') ans = ans.substr(1);
    if (!ans.empty() && ans.back() == '.') ans.pop_back();
    if(ans.empty()) ans = 'a';
    if (ans.size() > 15) ans = ans.substr(0, 15);
    if (!ans.empty() && ans.back() == '.') ans.pop_back();
    while(ans.size() <= 2) {
        ans.push_back(ans.back());
    }
    return ans;
}