#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int arr[6] = {500, 100, 50, 10, 5, 1}; // 500엔, 100엔, 50엔, 10엔, 5엔, 1
    int cnt = 0;

    N = 1000 - N; // pay
    for (int i = 0; i < 6; i++){
        cnt += N / arr[i];
        N = N % arr[i];
    }
    
    cout << cnt << endl;
}