#include <bits/stdc++.h>
using namespace std;

const int MAX = 5000000;
int N, K;
int arr[MAX];

int main() {
    ios::sync_with_stdio(0);
    
    cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    cout << arr[K -1];
}