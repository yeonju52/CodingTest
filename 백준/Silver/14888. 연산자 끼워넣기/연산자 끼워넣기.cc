#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, op[4];
vector<int> arr;

int mn = 1e9, mx = -1e9;

void bt(int val, int dep) {
    if (dep == N - 1) {
        mn = min(val, mn);
        mx = max(val, mx);
        return ;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;
            if (i == 0) bt(val + arr[dep + 1], dep + 1);
            else if (i == 1) bt(val - arr[dep + 1], dep + 1);
            else if (i == 2) bt(val * arr[dep + 1], dep + 1);
            else if (i == 3) bt(val / arr[dep + 1], dep + 1);
            op[i]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        arr.push_back(n);
    }
    for(int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    bt(arr[0], 0);

    cout << mx << "\n" << mn;
}