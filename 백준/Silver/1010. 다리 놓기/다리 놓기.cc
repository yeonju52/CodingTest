#include <bits/stdc++.h>
using namespace std;

int T, N, M;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> N >> M;
        N = min(M - N, N);
        int j = 1, m = 1;
        for (int i = 1; i <= N; i++) {
            j *= (M - i + 1);
            m *= i;
            int g = gcd(j, m);
            j /= g, m /= g;
        }
        cout << j / m << "\n";
    }
}