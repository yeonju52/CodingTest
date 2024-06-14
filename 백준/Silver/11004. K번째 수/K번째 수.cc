#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int A[5000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A + N);
    cout << A[K - 1] << '\n';
}