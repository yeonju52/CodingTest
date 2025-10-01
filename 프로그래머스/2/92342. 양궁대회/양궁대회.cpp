#include <bits/stdc++.h>

using namespace std;

int N, mx = -1;
vector<int> answer(11, -1);

void dfs(int idx, int cnt, vector<int> &A, vector<int> &B) {
    if (idx == 11) {
        A[10] += cnt;
        int sumA = 0, sumB = 0;
        for (int i = 0; i <= 10; i++) {
            if (A[i] == 0 && B[i] == 0) continue;
            if(A[i] > B[i]) sumA += (10 - i);
            else sumB += (10 - i);
        }
        int diff = sumA - sumB;
        if (diff > 0) {
            if (mx < diff) {
                mx = diff;
                answer = A;
            }
            else if (mx == diff) {
                for (int i = 10; i >= 0; i--) {
                    if (answer[i] == A[i]) continue;
                    if (answer[i] < A[i]) answer = A;
                    break;
                }
            }
        }
        A[10] -= cnt; // 복기 필수
        return ;
    }
    // 쏜다
    if (cnt > B[idx]) {
        A[idx] = B[idx] + 1;
        dfs(idx + 1, cnt - (B[idx] + 1), A, B);
        A[idx] = 0;
    }
    // 안쏜다
    dfs(idx + 1, cnt, A, B);
}

vector<int> solution(int n, vector<int> info) {
    N = n;
    
    vector<int> A(11, 0);
    dfs(0, N, A, info);
    
    if (answer[0] == -1) return {-1};
    return answer;
}