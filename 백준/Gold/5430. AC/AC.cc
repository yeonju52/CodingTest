#include <bits/stdc++.h>
using namespace std;

int T, N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--) {
		// 입력받기
		string cmd; cin >> cmd;
		cin >> N;
		
		string arr; cin >> arr;
		int sz = arr.size(), n = 0;
		deque<int> dq;
		for(int i = 1; i < sz - 1; i++) {
			if (arr[i] != ',') {
				n = (n * 10) + (arr[i] - '0');
			}
			else {
				dq.push_back(n);
				n = 0;
			}
		}
		if(arr.size() > 2) dq.push_back(n);
		
		// 명령어 수행
		bool rev = false, err = false;
		for (auto &c : cmd) {
			if (c == 'R') {
				rev = !rev;
			}
			else {
				if (dq.empty()) {
					err = true;
					break;
				}
				if (!rev) dq.pop_front();
				else dq.pop_back();
			}
		}

		// 출력하기
		if (err) {
			cout << "error\n";
		}
		else {
			int sz = dq.size();
			cout << '[';
			for (int i = 0; i < sz; i++) {
				if (!rev) {
					cout << dq.front();
					dq.pop_front();
					if (i < sz - 1) cout << ",";
				}
				else {
					cout << dq.back();
					dq.pop_back();
					if (i < sz - 1) cout << ",";
				}
			}
			cout << "]\n";
		}

	}
}
