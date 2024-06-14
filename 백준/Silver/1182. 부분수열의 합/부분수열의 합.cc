#include <iostream>
using namespace std;

int N, S;
int arr[21];
int cnt = 0;

void dfs(int i, int sum) {
  if (sum == S) {
    cnt++;
  }
  for (int posti = i + 1; posti < N; posti++) {
    dfs(posti, sum + arr[posti]);
  }
}

int main() {
  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < N; i++) {
    dfs(i, arr[i]);
  }
  cout << cnt;
}