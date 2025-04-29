#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    cin >> N;
    queue<int> arr;
    for (int i = 1; i <= N; i++) {
        arr.push(i);
    }

    while(arr.size() > 1) {
        arr.pop();
        arr.push(arr.front());
        arr.pop();
    }

    cout << arr.front();
    return 0;
}