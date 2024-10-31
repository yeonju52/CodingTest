#include <bits/stdc++.h>
using namespace std;

int N;
long long M;
int arr[10001];

// mid: 상한액 ? 전체 국가 예산 ? > '상한액'으로 선택
// 34%에서 문제
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(arr, 0, sizeof(arr));

    cin >> N;
    for (int i = 0; i < N; i++) { cin >> arr[i]; }
    cin >> M;

    int st = 0, ed = *max_element(arr, arr + N), mid;
    long long answer = M;
    while (st <= ed){
        mid = (st + ed) / 2;
        long long sumN = 0;
        for (int i = 0; i < N; i++){
            sumN += (long long)min(arr[i], mid);
        }
        if (sumN <= M){
            answer = mid;
            st = mid + 1;
        }
        else {
            ed = mid - 1;
        }
    }
    cout << answer << "\n";
    return 0;
}