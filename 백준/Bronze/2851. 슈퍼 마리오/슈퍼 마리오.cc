#include <iostream>
using namespace std;

int arr[10];
int sumArr[11];
int mini = 11;

int main() {
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    sumArr[0] = 0;
    for (int i = 1; i <= 10; i++) {
        sumArr[i] += (sumArr[i - 1] + arr[i - 1]);
    }
    // pivot
    int mini = 100;
    int minidx = 0;
    for (int i = 1; i <= 10; i++){
        int temp = abs(sumArr[i] - 100);
        if (mini >= temp){
            mini = temp;
            minidx = i;
        }
    }
    cout << sumArr[minidx] << endl;
}