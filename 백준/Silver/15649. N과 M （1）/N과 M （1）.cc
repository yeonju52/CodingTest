#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
  cin >> N >> M;
  
  vector<int> arr;  
  for (int i = 1; i <= N; i++) arr.push_back(i);
  
	do {
		for (int i = 0; i < M; i++) cout << arr[i] << " ";
		cout << "\n";
		reverse(arr.begin() + M, arr.end());
	} while (next_permutation(arr.begin(), arr.end()));

  return 0;
}
