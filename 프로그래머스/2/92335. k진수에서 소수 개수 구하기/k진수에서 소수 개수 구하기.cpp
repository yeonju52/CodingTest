#include <bits/stdc++.h>

using namespace std;

string getK(int n, int k) {
    string res = "";
    res += ((n % k) + '0');
    while((n /= k)) {
        res += ((n % k) + '0');
    }
    if (!res.empty()) reverse(res.begin(), res.end());
    return res;
}

int solution(int n, int k) {
    int ans = 0;
    stringstream ss(getK(n, k));
    string cur;
    while(getline(ss, cur, '0')) {
        if (cur.empty()) continue;
        long long P = stoll(cur);
        bool isP = (P < 2 ? false : true);
        for (long long i = 2; i * i <= P; i++) {
            if (!(P % i)) isP = false;
        }
        if (isP) ans++;
    }
    return ans;
}