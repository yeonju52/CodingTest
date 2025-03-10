#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long N, M, sumM, tree[1000000];
  cin >> N >> M;
  for (int i = 0; i < N; i++){
    cin >> tree[i];
  }

  long long st = 0, ed = *max_element(tree, tree + N), answer = 0, mid;

  while (st <= ed) {
    mid = (st + ed) / 2;

    long long sumM = 0;
    for (int i = 0; i < N; i++){
      if (tree[i] > mid) {
        sumM += (tree[i] - mid);
      }
    }
    if (sumM >= M) {
      st = mid + 1;
      answer = mid;
    }
    else {
      ed = mid - 1;
    }
  }

  cout << answer;
  return 0;
}