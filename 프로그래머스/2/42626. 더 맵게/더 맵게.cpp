#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while(!pq.empty()) {
        int f = pq.top(); pq.pop();
        if (f >= K) return ans;
        if (pq.empty()) return -1;
        int s = pq.top(); pq.pop();
        pq.push({f + s * 2});
        ans++;
    }
    return ans;
}