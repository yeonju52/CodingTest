#include <bits/stdc++.h>
using namespace std;

long L, P, V;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int idx = 0;
    while(true) {
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V ==0) break;
        cout << "Case " << ++idx << ": " << (V / P * L + min(L, V % P)) << "\n";
    }
    return 0;
}