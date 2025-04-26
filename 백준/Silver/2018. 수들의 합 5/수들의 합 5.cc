#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    
    int L = 1, R = 1, sum = 1, ans = 1;

    while (L <= N / 2) {
        if (sum == N) ans++;
        
        if (sum < N) sum += ++R;
        else sum -= L++;
    }
    
    cout << ans;
}