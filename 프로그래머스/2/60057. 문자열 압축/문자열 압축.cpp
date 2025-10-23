#include <bits/stdc++.h>

using namespace std;

string getUnit(stringstream &ss, int i) {
    char c;
    string res;
    while(ss >> c) {
        res += c;
        if(!(--i)) return res;
    }
    return res;
}

int solution(string s) {
    if (s.size() == 1) return 1;
    int ans = 1001;
    int N = s.size() / 2;
    
    for (int unit = 1; unit <= N; unit++) {
        stringstream ss(s);
        string res;
        string b = getUnit(ss, unit), c;
        int cnt = 1;
        while(!(c = getUnit(ss, unit)).empty()) {
            if (b == c) cnt++;
            else {
                if (cnt == 1) res += b;
                else res += (to_string(cnt) + b);
                cnt = 1, b = c;
            }
        }
        if (cnt == 1) res += b;
        else res += (to_string(cnt) + b);
        // cout << res << "\n";
        ans = min(ans, (int)res.size());
    }
    return ans;
}