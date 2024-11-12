#include <bits/stdc++.h>
using namespace std;

long long N, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int ans = 0;
    while(N > n){
        if (n == 0) n += 1;
        else n *= 2;
        ans++;
    }
    cout << ans;
}