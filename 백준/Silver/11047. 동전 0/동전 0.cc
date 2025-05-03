#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> arr;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;

    arr.resize(N, 0);
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr.begin(), arr.end(), greater<int>());

    int idx = 0;
    int ans = 0;
    while (K > 0) {
        if (K / arr[idx] > 0) {
            ans += K / arr[idx];
            K %= arr[idx];
        }
        idx++;
    }
    cout << ans;
}