#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int K[1000];
    int S[1000];
    memset(S, 0, sizeof(S));
    for (int i = 0; i < N; i++){
        cin >> K[i];
    }
    
    S[0] = K[0];
    S[1] = K[1];
    S[2] = K[2] + K[0];
    for (int i = 3; i < N; i++){
        if (K[i] + K[i - 3] > K[i] + K[i - 2]){
            S[i] = K[i] + K[i - 3];
        }
        else {
            S[i] = K[i] + K[i - 2];
        }
    }
    if (S[N-1] > S[N-2]){
        cout << S[N-1] << endl;
    }
    else {
        cout << S[N-2] << endl;;
    }
}