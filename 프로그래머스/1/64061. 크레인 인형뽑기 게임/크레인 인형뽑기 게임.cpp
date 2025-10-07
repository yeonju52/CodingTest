#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    
    int N = board.size();
    for (auto &c : moves) {
        c--;
        int cur = 0;
        for (int r = 0; r < N; r++) {
            if (board[r][c] != 0) {
                cur = board[r][c];
                board[r][c] = 0;
                // cout << c << "," << i << " 위치 ";
                break;
            }
        }
        if (cur == 0) continue;
        if (st.empty() || st.top() != cur) st.push(cur);
        else {
            answer += 2;
            st.pop();
        }
        // cout << cur << " " << st.size() << "\n";
    }
    return answer;
}