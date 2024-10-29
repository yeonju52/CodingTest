#include <iostream>
using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        long long answer = 0, sumN, N;
        cin >> N;

        long long start = 1, end = 1000000000, mid;
        while (start <= end){
            mid = (start + end) / 2;
            sumN = mid * (mid + 1) / 2;
            if (sumN <= N){
                start = mid + 1;
                answer = mid;
            }
            else {
                end = mid - 1;
            }
        }
        cout << answer << "\n";
    }
}