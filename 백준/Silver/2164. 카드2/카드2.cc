#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    cin >> N;
    deque<int> arr;
    for (int i = 1; i <= N; i++) {
        arr.push_back(i);
    }

    while(arr.size() > 1) {
        arr.pop_front();
        arr.push_back(arr.front());
        arr.pop_front();
    }

    cout << arr[0] << " ";
    return 0;
}