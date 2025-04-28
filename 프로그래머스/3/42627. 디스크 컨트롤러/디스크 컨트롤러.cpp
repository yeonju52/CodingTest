#include <bits/stdc++.h>

using namespace std;

struct prc {
    int i, s, l;
    bool operator>(const prc& other) const {
        if (l != other.l) return l > other.l;
        if (s != other.s) return s > other.s;
        return i > other.i;
    }
    
    void print() const {
        cout << i << " " << s << " " << l << "\n";
    }
    
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<prc, vector<prc>, greater<prc>> pq;
    
    int N = jobs.size();
    
    sort(jobs.begin(), jobs.end());
    
    int t = 0, i = 0, completed = 0;
    while (completed < N) {
        while (i < N && jobs[i][0] <= t) {
            pq.push({i, jobs[i][0], jobs[i][1]});
            i++;
        }
        
        if(!pq.empty()) {
            prc cur = pq.top(); pq.pop();
            t = max(t, cur.s) + cur.l;
            answer += (t - cur.s);
            completed++;
        }
        else {
            t++;
        }
    }
    answer /= N;
    return answer;
}