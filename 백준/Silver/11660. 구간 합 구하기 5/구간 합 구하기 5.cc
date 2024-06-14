#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;

  vector<vector<int>> arr(N, vector<int>(N, 0));
  vector<vector<int>> sumArr(N + 1, vector<int>(N + 1, 0));
  vector<vector<int>> xy(M, vector<int>(4, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < M; i++){
      cin >> xy[i][0] >> xy[i][1] >> xy[i][2] >> xy[i][3];
  }

  // sum[i][j] = arr[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      sumArr[i][j] = arr[i - 1][j - 1] + sumArr[i - 1][j] + sumArr[i][j - 1] -
                     sumArr[i - 1][j - 1];
    }
  }

  for (int i = 0; i < M; i++) {
    int x1 = xy[i][0], y1 = xy[i][1], x2 = xy[i][2], y2 = xy[i][3];
    cout << (sumArr[x2][y2] - sumArr[x2][y1 - 1] - sumArr[x1 - 1][y2] +
             sumArr[x1 - 1][y1 - 1]) << '\n';
  }
}