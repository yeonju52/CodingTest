#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pll;

priority_queue<int> pq;
queue<pll> q;
int solution(vector<int> priorities, int location) {
    int ans = 0;
    int N = priorities.size();
    for (int i = 0; i < N; i++) {
        pq.push(priorities[i]);
        q.push({priorities[i], i});
    }
    
    pll cur;
    while(!pq.empty()) {
        int tar = pq.top(); pq.pop();
        ++ans;
        while(!q.empty()) {
            cur = q.front(); q.pop();
            if (tar == cur.first) break;
            else q.push(cur);
        }
        if (cur.second == location) break;
    }
    return ans;
    
    // queue
}