#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr, lis;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    arr.resize(N, 0);
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]); // '증가'하는 수열이므로 upper_bound X
        if (it == lis.end()) lis.push_back(arr[i]);
        else *it = arr[i];
    }

    cout << lis.size();
    return 0;
}