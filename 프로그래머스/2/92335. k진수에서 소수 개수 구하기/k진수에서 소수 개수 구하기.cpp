#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;
int prm[MAX];

string dfs(int n, int k) {
    if (n < k) return to_string(n % k);
    return dfs(n / k, k) + to_string(n % k);
}

bool isPrime(long long val) {
    if (val < 2) return false;
    if (val == 2) return true;
    if (val % 2 == 0) return false;
    for (long long i = 3; i * i <= val; i += 2) {
        if (val % i == 0) return false;
    }
    return true;
}

int findPrime(string s) {
    auto nxt = s.find("0");
    if (nxt == string::npos) {
        return (!s.empty() && isPrime(stoll(s))) ? 1 : 0;
    }
    string P = s.substr(0, nxt);
    if (!P.empty() && isPrime(stoll(P))) return findPrime(s.substr(nxt + 1)) + 1;
    return findPrime(s.substr(nxt + 1));
}

int solution(int n, int k) {
    return findPrime(dfs(n, k));
}