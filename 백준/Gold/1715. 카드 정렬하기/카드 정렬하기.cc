#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    int ans = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        pq.push(x);
    }

    while(pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += (a + b);
        pq.push(a + b);
    }
    cout << ans << "\n";
}