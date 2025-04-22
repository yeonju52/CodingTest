#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<int> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--) {
        int val; cin >> val;
        if (val == 0) {
            if (arr.empty()) cout << "0\n";
            else {
                cout << arr.top() << "\n";
                arr.pop();
            }
        }
        else {
            arr.push(val);
        }
    }
    return 0;
}