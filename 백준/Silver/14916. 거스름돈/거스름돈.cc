#include <bits/stdc++.h>
using namespace std;

int N;
int ans = 0;
    
int main(){
    cin >> N;
    while (N > 1 && N % 5 != 0) {
        N -= 2;
        ans++;
    }
    if (N % 5 == 0) { cout << (ans + N / 5); }
    else cout << -1;
}