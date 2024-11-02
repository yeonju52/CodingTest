#include <bits/stdc++.h>
using namespace std;

int N;
long long M;
long long tree[1000002];

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        cin >> tree[i];
    }

    long long st = 0, end = *max_element(tree, tree + N), answer = 0, mid;
    while(st <= end){
        mid = (st + end) / 2;
        long long sumM = 0;
        for (int i = 0; i < N; i++){
            sumM += (tree[i] - min(mid, tree[i]));
        }
        if (sumM >= M) {
            st = mid + 1;
            answer = mid;
        }
        else {
            end = mid - 1;
        }
    }
    cout << answer;
}