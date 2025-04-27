#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int N = board.size(), M = board[0].size();
    vector<vector<int>> sumA(N + 2, vector<int>(M + 2, 0));
    
    for (auto &t : skill) {
        int sign = t[0] == 1 ? -1 : 1;
        int x1 = t[1], y1 = t[2], x2 = t[3], y2 = t[4], am = t[5] * sign;
        
        // sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + board[i][j]
        sumA[x1][y1] += am;
        sumA[x2 + 1][y1] -= am;
        sumA[x1][y2 + 1] -= am;
        sumA[x2 + 1][y2 + 1] += am;
    }

    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < M + 1; j++) {
            sumA[i + 1][j] += sumA[i][j];
        }
    }
    
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < M + 1; j++) {
            sumA[i][j + 1] += sumA[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] + sumA[i][j] > 0) answer++;
        }
    }
    
    return answer;
}