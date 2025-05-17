#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, K;
struct wv{
    int w, v;
    bool operator<(const wv &other) const {
        if (w != other.w) return w < other.w;
        return v > other.v;
    }
    // bool operator>(const wv &other) const {
    //     if (w != other.w) return w > other.w;
    //     return v < other.v;
    // }
};

priority_queue<int> pq;
vector<wv> arr;
vector<ll> bag;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int w, v; cin >> w >> v;
        arr.push_back({w, v});
    }
    bag.resize(K, 0);
    for (int i = 0; i < K; i++) cin >> bag[i];

    sort(bag.begin(), bag.end());
    sort(arr.begin(), arr.end());
    
    ll ans = 0;
    auto it = arr.begin();
    for (auto &w : bag) {
        while(it != arr.end()) {
            if (it->w > w) break;
            pq.push(it->v);
            it++;
        }
        if (!pq.empty()) {
            ans += ll(pq.top());
            pq.pop();
        }
    }
    cout << ans;
}