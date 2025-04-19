#include <iostream>
#include <vector>
using namespace std;

int N, M;

void getnCm(int dep, vector<int> &vis);

int main() {
  cin >> N >> M;

  vector<int> vis(M, 0);
  getnCm(0, vis);
  
  return 0;
}

void getnCm(int dep, vector<int> &vis) {
  if (dep == M) {
    for (int i = 0; i < M; i++) {
      cout << vis[i] << " ";
    }
    cout << "\n";
    return;
  }
  for (int i = 1; i <= N; i++) {
    if (dep > 0 && vis[dep - 1] > i) continue;
    vis[dep] = i;
    getnCm(dep + 1, vis);
    // vis[dep] = 0; // i 값을 덮어쓰기 때문에, 굳이 필요 없음
  }
}