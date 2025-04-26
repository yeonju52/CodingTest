#include <bits/stdc++.h>
using namespace std;

int N, K, Q, M;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K >> Q >> M;

    // unordered_set<int> sleep;
    vector<int> sleep(N + 3, 0);
    while(K--) {
        int idx; cin >> idx;
        sleep[idx] = 1;
        // sleep.insert(idx);
    }

    vector<int> book(N + 3, 1);
    book[0] = book[1] = book[2] = 0; // 출석 안 한 사람 = 1

    while(Q--) {
        int i; cin >> i;
        if (sleep[i]) continue; // 처음 받은 사람이 자고 있으면 전파를 못함
        int idx = i;
        while(idx < N + 3) {
            // 잠 x -> 출석체크 함
            if (!sleep[idx]) book[idx] = 0;
            idx += i;
        }
    }
    
    // 누적합 구하기
    vector<int> prefixS(N + 4, 0);
    for (int i = 3; i < N + 3; i++) { // 3 ~ N + 2
        prefixS[i + 1] = prefixS[i] + book[i]; // PrefixSum = 3 ~ N + 3
    }

    while(M--) {
        int L, R; cin >> L >> R;
        cout << prefixS[R + 1] - prefixS[L] <<"\n";
    }
}