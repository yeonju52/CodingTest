#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1001;

ll T, ans = 0;
int N, M, A[MAX], B[MAX];
vector<int> sumA, sumB;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    cin >> N;
    for (int i = 1; i <= N; i++) { cin >> A[i]; A[i] += A[i - 1]; }
    for (int i = 0; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            sumA.push_back(A[j] - A[i]);
        }
    }
    cin >> M;
    for (int i = 1; i <= M; i++) { cin >> B[i]; B[i] += B[i - 1]; }
    for (int i = 0; i <= M; i++) {
        for (int j = i + 1; j <= M; j++) {
            sumB.push_back(B[j] - B[i]);
        }
    }

    // ___bound 쓰기전에 정렬 필수
    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());
    auto it = sumA.begin();
    while(it != sumA.end()) {
        int a = *it, b = T - *it;
        int cntA = upper_bound(sumA.begin(), sumA.end(), a) - lower_bound(sumA.begin(), sumA.end(), a);
        int cntB = upper_bound(sumB.begin(), sumB.end(), b) - lower_bound(sumB.begin(), sumB.end(), b);
        ans += (1LL * cntA * cntB);
        it += cntA;
    }
    cout << ans;
}
