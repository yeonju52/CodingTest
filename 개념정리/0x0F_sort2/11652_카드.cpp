// 음수일 때와 양수일 때, 대소비교 반대로
// ~2^63 ~ 2^63 - 1 까지는 long long으로 커버 가능
// string으로 받아야할 듯
// long long maxval = -(111 << 62) - 1
#include <bits/stdc++.h>
using namespace std;

int N;
string arr[100002];

bool cmp(string &a, string &b){ // 음수 처리 추가
    if (a[0] == '-' && b[0] != '-') return true;
    if (a[0] != '-' && b[0] == '-') return false;
    if (a[0] != '-'){
        if (a.length() != b.length()) return a.length() < b.length();
        return a < b;
    }
    else {
        if (a.length() != b.length()) return a.length() > b.length();
        return a > b;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N, cmp);

    string maxi = arr[0];
    int maxdup = 0;
    int dup = 0;
    for (int i = 0; i < N - 1; i++){
        if (arr[i] != arr[i + 1]) dup = 0;
        else dup++;

        if (maxdup < dup) {
            maxdup = dup;
            maxi = arr[i];
        }
    }
    cout << maxi;
}