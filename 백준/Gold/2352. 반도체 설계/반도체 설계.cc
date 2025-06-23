#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 40001;

int arr[MAX];
vector<int> dp;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    // DP - LIS
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (it == dp.end()) {
            dp.push_back(arr[i]); // x가 가장 크면 lis 확장
        } else {
            *it = arr[i]; // x가 들어갈 자리에 교체
        }
    }
    cout << dp.size();
}