#include <iostream>
#include <string>
using namespace std;

string arr[30];

//1
//abxbbxa
//1
//abxxbxa
int flag = 1;

bool checkRecur(int i, int st, int ed) {
	while (st < ed) { // 등호 빼도 OK, 홀수 일 때는 같을 때 항상 동일하니까
		if (arr[i][st] == arr[i][ed]) {
			st++; ed--; // 완전 회전문: flag = 1;
		}
		else {
			if (!flag) { // flag == 0
				return false;
			}
			flag = 0; // 수정 회전문: flag = 0;
			return checkRecur(i, st + 1, ed) || checkRecur(i, st, ed - 1);
		}
	}
	return true;
}

int main() {
	int T;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < T; i++) {
		flag = 1;
		bool isValid = checkRecur(i, 0, arr[i].size()-1);
		if (isValid) {
			if (flag) {
				cout << 0 << endl;
			}
			else {
				cout << 1 << endl;
			}
		}
		else {
			cout << 2 << endl;
		}
	}
}