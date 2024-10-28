#include <bits/stdc++.h>
using namespace std;

long long X, Y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> X >> Y;
    int Z = Y * 100 / X;
    if (Z >= 99) {
        cout << -1;
        return 0;
    }

    long long k = ((Z + 1) * X - 100 * Y + (100 - (Z + 1)) - 1) / (100 - (Z + 1));
    cout << k;
    return 0;
}
