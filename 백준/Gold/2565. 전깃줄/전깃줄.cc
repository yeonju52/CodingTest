#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int N;
vector<P> arr;
vector<int> lis;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());
    
    vector<int> B;
    for (auto &p : arr) B.push_back(p.second);

    lis.resize(N, 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (B[j] < B[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    cout << N - *max_element(lis.begin(), lis.end());
}