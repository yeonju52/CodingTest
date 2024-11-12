#include <bits/stdc++.h>
using namespace std;

int N;
int arr[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = N - 2; i >= 0; i--){
        if (arr[i + 1] > arr[i]) continue;
        int tar = (arr[i] - arr[i + 1] + 1);
        ans += tar;
        arr[i] -= tar;
    }
    cout << ans;
}