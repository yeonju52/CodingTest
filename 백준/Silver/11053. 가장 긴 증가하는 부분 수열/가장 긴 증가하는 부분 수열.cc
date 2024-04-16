#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int N;
    int v;
    int A[1000];
    int dp[1001];
    int idx = 1;
    memset(dp, 0, sizeof(dp));
    memset(A, 0, sizeof(A));
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A[i];
        if (i == 0){
            dp[i] = 1;
        }
        int maxi = 1;
        for (int j = 0; j < i; j++){
            if (A[j] < A[i]){
                // dp[i] = dp[j] + 1;
                if (dp[j] + 1 > maxi){
                    maxi = dp[j] + 1;
                }
            }
            dp[i] = maxi;
        }
        if (dp[i] > idx){
            idx = dp[i];
        }
    }
    cout << idx;
}