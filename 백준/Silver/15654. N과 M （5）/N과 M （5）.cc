#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;

void nPm(int cur, vector<int> &vis);

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    int v; cin >> v;
    arr.push_back(v);
  }
  sort(arr.begin(), unique(arr.begin(), arr.end()));
  N = arr.size();

  vector<int> vis(M, 0);
  nPm(0, vis);
}

void nPm(int cur, vector<int> &vis) {
  if (cur == M) {
    for (auto &v : vis) {
      cout << v << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; i++) {
    if (find(vis.begin(), vis.end(), arr[i]) != vis.end()) continue;
    vis[cur] = arr[i];
    nPm(cur + 1, vis);
    vis[cur] = 0;
  }
}