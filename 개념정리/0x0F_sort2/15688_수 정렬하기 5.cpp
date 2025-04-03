// 계수정렬: freq에 저장
#include <bits/stdc++.h>
using namespace std;

int N;
int freq[2000001]; // ~1,000,000 ~ 0 ~ 1,000,000

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(freq, 0, sizeof(freq));

    cin >> N;
    for (int i = 0; i < N; i++){
        int tmp; cin >> tmp;
        freq[tmp + 1000000]++;
    }

    for (int i = 0; i <= 2000000; i++){
        while(freq[i]--){
            cout << i - 1000000 << '\n';
        }
    }
}