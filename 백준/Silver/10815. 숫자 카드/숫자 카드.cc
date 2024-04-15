#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
long A[500000];
long val;

bool bnSearch(int st, int ed){
    if (st > ed){
        return false;
    }
    
    int mid = (st + ed) / 2;
    if (A[mid] == val){
        return true;
    }
    else if (A[mid] < val){ // 
        return bnSearch(mid + 1, ed);
    }
    else {
        return bnSearch(st, mid - 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A + N); // 정렬
    cin >> M;
    for (int i = 0; i < M; i++){
        cin >> val;
        cout << bnSearch(0, N - 1) << " ";
    }
}