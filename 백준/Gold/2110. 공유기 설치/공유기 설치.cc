#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, C, dist[200001];

  cin >> N >> C;
  for (int i = 0; i < N; i++){
    cin >> dist[i];
  }

  sort(dist, dist + N);
  
  int st = 1, ed = dist[N - 1] - dist[0], ans = 0;

  while (st <= ed) {
    long long mid = (st + ed) / 2;
    int cnt = 1;
    int cur = dist[0];

    for (int i = 1 ;i < N; i++){
      if (dist[i] - cur >= mid) {
        cnt++;
        cur = dist[i];
      }
    }

    if (cnt >= C) {
      st = mid + 1;
      ans = mid;
    }
    else {
      ed = mid - 1;
    }
  }

  cout << ans << "\n";
}