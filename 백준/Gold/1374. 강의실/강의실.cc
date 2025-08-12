#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
struct ise {
    int s, e, i;
    bool operator<(const ise& other) const {
        if (s != other.s) return s > other.s;
        if (e != other.e) return e > other.e;
        return i > other.i;
    }
};

int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    priority_queue<ise> pq;
    for (int t = 0; t < N; t++) {
        int i, s, e; cin >> i >> s >> e;
        pq.push({s, e, i});
    }
    
    ise st = pq.top(); pq.pop();
    multiset<int> room = {st.e}; // 끝나는 시간
    while(!pq.empty()) {
        ise cur = pq.top(); pq.pop();
        auto it = room.upper_bound(cur.s); // cur.s 보다 큰 가장 작은 인덱스
        if (it != room.begin()) {
            --it;
            room.erase(it);
            room.insert(cur.e);
        } else {
            room.insert(cur.e);
        }
    }

    cout << room.size();
    return 0;
}