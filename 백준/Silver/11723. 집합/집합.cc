#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int arr[21];

void fadd(int x);
void fremove(int x);
void fcheck(int x);
void ftoggle(int x);
void fall();
void fempty();

int main() {
	int N;

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin.ignore(); // 개행문자 제거

	memset(arr, 0, sizeof(arr));

	while (N--) {
		string s, cmd;
		int x = 0;

		getline(cin, s);
		int idx = s.find(" ");
		if (idx == string::npos) {
			cmd = s;
		}
		else {
			cmd = s.substr(0, idx);
			x = stoi(s.substr(idx + 1));
		}

		if (cmd == "add") fadd(x);
		else if (cmd == "remove") fremove(x);
		else if (cmd == "check") fcheck(x);
		else if (cmd == "toggle") ftoggle(x);
		else if (cmd == "all") fall();
		else if (cmd == "empty") fempty();

	}
	return 0;
}

void fadd(int x) {
	arr[x] = 1;
}
void fremove(int x) {
	arr[x] = 0;
}

void fcheck(int x) {
	cout << arr[x] << "\n";
}

void ftoggle(int x) {
	arr[x] = 1 - arr[x];
}

void fall() {
	fill(arr, arr + 21, 1);
}

void fempty() {
	memset(arr, 0, sizeof(arr));
}