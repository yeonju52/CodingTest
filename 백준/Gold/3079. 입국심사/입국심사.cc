#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll M, ans;
vector<ll> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    arr.resize(N, 0);
    for (int i = 0; i < N; i++) cin >> arr[i];

    ll st = 0, ed = *max_element(arr.begin(), arr.end()) * M, mid, sum;
    while (st <= ed) {
        mid = st + (ed - st) / 2;
        sum = 0;
        for (int i = 0; i < N && sum < M; i++) sum += (mid / arr[i]);
        if (sum >= M) ans = mid, ed = mid - 1;
        else st = mid + 1;
    }
    cout << ans;
}