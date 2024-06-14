#include <iostream>
#include <algorithm>
using namespace std;

int n, x;
int arr[100000];

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> x;

    sort(arr + 0, arr + n);

    int st = 0, ed = n - 1;
    int result = 0;
    
    int temp;
    while(st < ed){ // 같을 때는 당연히 안 됨
        temp = arr[st] + arr[ed];
        if (temp == x){
            st++; ed--;
            result++;
        }
        else if (temp > x){ // 목표값보다 크다. 줄여야지
            ed--;
        }
        else { //temp < x // 목표값보다 작다. 늘려야된다.
            st++;
        }
    }
    cout << result;
}