#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int N;
int val;
int arr[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < N; i++){
        cin >> val;
        arr[val]++;
    }
    // 최대: 10000 * 10000000
    for (int i = 1; i < 10001; i++){
        while(arr[i]--){
            cout << i << '\n';
        }   
    }
}