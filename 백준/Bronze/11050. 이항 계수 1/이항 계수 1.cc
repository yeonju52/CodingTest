#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, tmp, ans = 1;
    cin >> N >> K;

    tmp = N;
    for (int i = 0; i < K; i++) ans *= tmp--;
    tmp = K;
    while(tmp > 1) ans /= tmp--;
    cout << ans;
}