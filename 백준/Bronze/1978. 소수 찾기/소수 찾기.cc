#include <iostream>

using namespace std;

bool isPrime(int a) {
    if (a == 1) return false;
    
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++){
        int a; cin >> a;

        if (isPrime(a)) {
            sum++;
        }
    }

    cout << sum << "\n";
}