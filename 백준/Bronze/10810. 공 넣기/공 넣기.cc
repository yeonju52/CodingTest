#include <bits/stdc++.h>
using namespace std;

int N, M, arr[101];

int main() {
	cin >> N >> M;
	while(M--) {
		int i, j, k; cin >> i >> j >> k;
		for (int cur = i; cur <= j; cur++) {
			arr[cur] = k;
		}
	}

	for (int i = 1; i <= N; i++) cout << arr[i] << " ";
}
