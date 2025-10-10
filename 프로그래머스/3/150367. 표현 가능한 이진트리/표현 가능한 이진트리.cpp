#include <bits/stdc++.h>

using namespace std;

string nbit(long long x) {
    string res;
    if (x == 0) return "0";
    else {
        while(x > 0) {
            res = ((x & 1) ? "1" : "0") + res;
            x >>= 1;
        }
    }
    
    int n = res.size();
    int k = 1;
    while((1 << k) - 1 < n) k++;
    res = string((1 << k) - 1 - n, '0') + res;
    return res;
}

bool isBT(string &s, int l, int r) {
    if (l > r) return true;
    int mid = (l + r) / 2;
    char parent = s[mid];
    
    int ll = l, lr = mid - 1;
    int rl = mid + 1, rr = r;
    
    if (parent == '0') {
        for (int i = ll; i <= lr; i++) if (s[i] == '1') return false;
        for (int i = rl; i <= rr; i++) if (s[i] == '1') return false;
        return true;
    }
    
    return isBT(s, ll, lr) && isBT(s, rl, rr);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> ans;
    for (auto &cur : numbers) {
        string s = nbit(cur);
        ans.push_back(isBT(s, 0, s.size() - 1));
    }
    return ans;
}