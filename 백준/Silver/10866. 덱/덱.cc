#include<iostream>
#include<deque>

using namespace std;

int N;
deque<int> dq;

int main(int argc, char** argv)
{
	cin >> N;
	while(N--) {
		string cmd; cin >> cmd;
		int res;
		if (cmd == "push_front") {
			int val; cin >> val;
			dq.push_front(val);
		}
		else if (cmd == "push_back") {
			int val; cin >> val;
			dq.push_back(val);
		}
		else if (cmd == "pop_front") {
			if (dq.empty()) res = -1;
			else {
				res = dq.front(); dq.pop_front();
			}
			cout << res << "\n";
		}
		else if (cmd == "pop_back") {
			if (dq.empty()) res = -1;
			else {
				res = dq.back(); dq.pop_back();
			}
			cout << res << "\n";
		}
		else if (cmd == "size") {
			res = dq.size();
			cout << res << "\n";
		}
		else if (cmd == "empty") {
			if (dq.empty()) res = true;
			else res = false;
			cout << res << "\n";
		}
		else if (cmd == "front") {
			if (dq.empty()) res = -1;
			else res = dq.front();
			cout << res << "\n";
		}
		else if (cmd == "back") {
			if (dq.empty()) res = -1;
			else res = dq.back();
			cout << res << "\n";
		}
	}
}
