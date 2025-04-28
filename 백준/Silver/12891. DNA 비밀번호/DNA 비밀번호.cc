#include <bits/stdc++.h>
using namespace std;

int S, P;
string s;
string prefix = "ACGT";
unordered_map<char, int> rev = {{'A', 0}, {'C', 1 }, {'G', 2}, {'T', 3}};
int ACGT[4];
int cnt[4];

bool isValid() { // 조건 확인
    for (int i = 0; i < 4; i++) if (ACGT[i] > cnt[i]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> P >> s >> ACGT[0] >> ACGT[1] >> ACGT[2] >> ACGT[3];
    
    int ans = 0;
    
    // 초기화
    for (int i = 0; i < 4; i++) cnt[i] = count(s.begin(), s.begin() + P, prefix[i]);
    if (isValid()) ans++;
    
    // 탐색 시작
    int prev_st = 0, ed = prev_st + P;
    while (ed < S) {
        cnt[rev[s[prev_st]]]--, cnt[rev[s[ed]]]++;
        if (isValid()) ans++;

        prev_st++, ed++;
    }

    cout << ans;
}