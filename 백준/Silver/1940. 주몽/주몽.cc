#include <bits/stdc++.h>
using namespace std;

const int MAX = 15000;
int a[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a, a + N);

    int L = 0, R = N - 1, ans = 0;
    while(L < R) {
        int sum = a[L] + a[R];
        if (sum == M) ans++, L++, R--;
        else if (sum < M) L++;
        else R--;
    }
    cout << ans;
}