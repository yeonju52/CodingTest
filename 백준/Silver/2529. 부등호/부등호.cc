#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
string brt, mn, mx, comp;

void getBrt(string tar, string other, int n) {
    if (n == N) {
        mn = min(mn, tar), mx = max(mx, tar); // get 정답
        return ;
    }
    if (comp[n] == '<') {
        for (int i = 0; i < 9 - n; i++) {
            if (tar.back() < other[i]) getBrt(tar + other[i], other.substr(0, i) + other.substr(i + 1), n + 1);
        }
    }
    else {
        for (int i = 0; i < 9 - n; i++) {
            if (tar.back() > other[i]) getBrt(tar + other[i], other.substr(0, i) + other.substr(i + 1), n + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력
    cin >> N;
    for (int i = 0; i < N; i++) { char c; cin >> c; comp += c; }
    
    // 2. 정답 초기화
    mn.resize(N + 1, char('9' + 1)), mx.resize(N + 1, char('0' - 1));
    
    // 3. 조합 찾기
    for (int i = 0; i <= 9; i++) {
        string allNum = "0123456789";
        getBrt(to_string(i), allNum.substr(0, i) + allNum.substr(i + 1), 0);
    }
    
    cout << mx << "\n" << mn;
}