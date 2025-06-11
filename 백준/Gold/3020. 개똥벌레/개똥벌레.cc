#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int N, H;
vector<int> arrA, arrB; // 석순, 종유석

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> H;
    for (int i = 0; i < N; i++) {
        int len; cin >> len;
        if (i % 2 == 0) arrA.push_back(len);
        else arrB.push_back(len);
    }
    sort(arrA.begin(), arrA.end());
    sort(arrB.begin(), arrB.end());

    int minCnt = 200000, ans = 0;
    for (int i = 1; i <= H; i++) { 
        int cnt = 0;
        cnt += int(arrA.size()) - (lower_bound(arrA.begin(), arrA.end(), i) - arrA.begin());
        cnt += int(arrB.size()) - (lower_bound(arrB.begin(), arrB.end(), H - i + 1) - arrB.begin());
        if (cnt < minCnt) {
            minCnt = cnt;
            ans = 1;
        }
        else if (cnt == minCnt) ans++;
    }
    cout << minCnt << " " << ans;
}