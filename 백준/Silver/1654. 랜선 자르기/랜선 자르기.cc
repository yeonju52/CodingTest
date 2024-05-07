#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000000];
int N, K;
long long answer = 0;

void laneK(){
    long long st = 1, ed = arr[0]; // 최대 길이
    long long mid;
    int cnt;

    while(st <= ed){
        mid = (st + ed) / 2;
        cnt = 0;
        for (int i = 0; i < N; i++){
            cnt += (int)(arr[i] / mid);
        }
        if (cnt >= K){
            st = mid + 1;
            if (answer < mid){
                answer = mid;
            }
        }
        else {
            ed = mid - 1;
        }
    }

}

int main(){
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr + N, greater<long long>());
    laneK();
    cout << answer;
}