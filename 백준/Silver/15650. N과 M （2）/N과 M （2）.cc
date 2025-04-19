#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;

int main() {
  cin >> N >> M;
  
  vector<int> brute(N, 0);
  fill(brute.begin(), brute.begin() + M, 1);
  
  do {
    for (int i = 0; i < N; i++) {
      if (brute[i]) cout << i + 1 << " ";
    }
    cout << "\n";
  } while (prev_permutation(brute.begin(), brute.end()));
  
  return 0;
}