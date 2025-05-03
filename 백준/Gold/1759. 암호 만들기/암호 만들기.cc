#include <bits/stdc++.h>
using namespace std;

int C, N;
char board[15];
set<string> ans;

string aeiou = "aeiou";

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> C >> N;
    for (int i = 0; i < N; i++) cin >> board[i];
    sort(board, board + N); // 입력 배열 정렬 필수

    vector<int> brute(N, 0);
    for (int i = N - C; i < N; i++) brute[i] = 1;

    do {
        string s = "";
        int mcnt = 0;
        for (int i = 0; i < N; i++) {
            if (!brute[i]) continue;
            if (find(aeiou.begin(), aeiou.end(), board[i]) != aeiou.end()) mcnt++;
            s += board[i];
        }
        if (mcnt > 0 && C - mcnt > 1) ans.insert(s); // 자음 개수도 확인해야함 (ex. aei)
    } while(next_permutation(brute.begin(), brute.end()));

    for (auto &a : ans) cout << a << "\n";
}