#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, vector<vector<int>> &safeArr, int N){
    safeArr[x][y] = 0;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N){
            if (safeArr[nx][ny]){
                dfs(nx, ny, safeArr, N);
            }
        }
    }
    
}
int countSafeArea(int thresh, vector<vector<int>> &arr, int N){
    vector<vector<int>> safeArr(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (arr[i][j] > thresh){
                safeArr[i][j] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (safeArr[i][j]){
                dfs(i, j, safeArr, N);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int N;
    cin >> N;

    vector<vector<int>> Arr(N, vector<int>(N));
    vector<vector<int>> SafeArr(N, vector<int>(N, 0));
    int maxi = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> Arr[i][j];
            if (maxi < Arr[i][j]){
                maxi = Arr[i][j];
                // FIXEDME: max_element 쓰는 방법 고민 (2차원 벡터 + sort/max)
                // vector<int>::iterator iter = *max_element(arr.begin(), arr.end(); 어떻게 쓸까 고민해보자
            }
        }
    }
    int maxArea = 1; // idx = maxi일 때
    for (int th = maxi - 1; th > 0; th--){
        int cnt = countSafeArea(th, Arr, N);
        if (maxArea < cnt){
            maxArea = cnt;
        }
    }

    cout << maxArea;
}