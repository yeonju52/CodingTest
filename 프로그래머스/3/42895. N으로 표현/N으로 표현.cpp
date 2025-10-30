#include <bits/stdc++.h>

using namespace std;

int solution(int N, int number) {
    unordered_set<int> dp[9];
    dp[0].insert(0);
    for (int i = 1; i <= 8; i++) {
        dp[i].insert(stoi(string(i, N + '0')));
         for (int j = 1; j < i; j++) {
            for (int a : dp[j]) {
                for (int b : dp[i - j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) dp[i].insert(a / b);
                }
            }
        }
        if (dp[i].count(number)) return i;
    }
    
    return -1;
}