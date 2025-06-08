#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int T, N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> N >> M;
        vector<int> A, B;
        for (int i = 0; i < N; i++) { int a; cin >> a; A.push_back(a); }
        for (int i = 0; i < M; i++) { int b; cin >> b; B.push_back(b); }
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int cnt = 0;
        for (auto &a : A) {
            cnt += (lower_bound(B.begin(), B.end(), a) - B.begin());
        }
        cout << cnt << "\n";
    }
}