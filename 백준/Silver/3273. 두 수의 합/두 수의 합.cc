#include <bits/stdc++.h>
using namespace std;

int a[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int X; cin >> X;

    sort(a, a + N);

    int ans = 0, L = 0, R = N - 1;
    while(L < R) {
        int sumA = a[L] + a[R];
        if (sumA == X) { ans++; R--, L++; }
        else if (sumA < X) L++;
        else R--;
    }
    cout << ans;
}