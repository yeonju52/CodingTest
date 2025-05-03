#include <bits/stdc++.h>
using namespace std;

int a, b;
int prime[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b;
    
    int mini = min(a, b);
    int maxi = max(a, b);
    
    fill(prime, prime + maxi + 1, 1);
    prime[0] = 0, prime[1] = 0;
    for (int i = 2; i * i <= b; i++) {
        if (prime[i] == 0) continue;
        for (int j = i; i * j <= b; j++) {
            prime[i * j] = 0;
        }
    }
    for (int i = a; i <= b; i++) if (prime[i]) cout << i << "\n";
}