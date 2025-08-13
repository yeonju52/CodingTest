#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int ans = 0;
    int N = triangle.size();
    for (int i = 1; i < N; i++) {
        triangle[i][0] += triangle[i-1][0];
        for (int j = 1; j < i; j++) {
            triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
        }
        triangle[i][i] += triangle[i-1][i-1];
        ans = max(ans, *max_element(triangle[i].begin(), triangle[i].end()));
    }
    return ans;
}