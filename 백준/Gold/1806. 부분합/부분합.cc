#include <iostream>
using namespace std;

int N, S;
int arr[100000];
int sumArr[100001];
int mini = 100001;

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sumArr[0] = 0;
	for (int i = 1; i <= N; i++) {
		sumArr[i] += (sumArr[i - 1] + arr[i - 1]);
	}
	// Si-j = Si+1 - Sj
	int st = 0, ed = 1;
	int sum = 0;
	while (st < ed && ed <= N) {
		sum = sumArr[ed] - sumArr[st];
		if (sum >= S) {
			mini = min(mini, ed - st);
			sum -= sumArr[st];
			st++;
		}
		else {
			ed++;
		}
	}
	if (mini == 100001) {
		cout << 0 << endl;
	}
	else {
		cout << mini << endl;
	}
}