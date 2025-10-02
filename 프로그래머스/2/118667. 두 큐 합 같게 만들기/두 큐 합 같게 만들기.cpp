#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int ans = 0;
    long long L = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long R = accumulate(queue2.begin(), queue2.end(), 0LL);
    queue<int> q1, q2;
    for (auto &cur : queue1) q1.push(cur);
    for (auto &cur : queue2) q2.push(cur);
    
    int N = queue1.size() + queue2.size();
    while(L != R) {
        ans++;
        if (ans >= 2 * N) {
            ans = -1;
            break;
        }
        if (L < R) {
            q1.push(q2.front());
            L += q2.front(), R -= q2.front();
            q2.pop();
        }
        else { // L > R
            q2.push(q1.front());
            L -= q1.front(), R += q1.front();
            q1.pop();
        }
    }
    
    return ans;
}