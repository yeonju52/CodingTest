#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr, sort_arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    arr.resize(N, 0);
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort_arr = arr;
    sort(sort_arr.begin(), sort_arr.end());
    sort_arr.erase(unique(sort_arr.begin(), sort_arr.end()), sort_arr.end());

    for (auto &a : arr) cout << lower_bound(sort_arr.begin(), sort_arr.end(), a) - sort_arr.begin() << " ";
}