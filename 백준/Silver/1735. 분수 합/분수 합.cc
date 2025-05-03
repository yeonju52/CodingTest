#include <bits/stdc++.h>
using namespace std;

int gcd(int A, int B) {
    if (B == 0) return A;
    return gcd(B, A % B);

}

int main() {
    int A1, B1, A2, B2;
    cin >> A1 >> B1 >> A2 >> B2;
    int A = A1 * B2 + A2 * B1, B = B1 * B2;

    if (A == 0 || B == 0) {
        cout << "0 1";
        return 0;
    }

    int val = gcd(A, B);
    cout << A / val << " " << B / val;
}