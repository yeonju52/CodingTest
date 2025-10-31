#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<pair<int, int>> arr;
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        arr.push_back({s, e});
    }
    sort(arr.begin(), arr.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &[s, e] : arr) {
        if (!pq.empty() && pq.top() <= s) pq.pop();
        pq.push(e);
    }
    cout << pq.size();
}