#include <bits/stdc++.h>
using namespace std;

int N;
string arr[52];

bool cmp(string a, string b){
    if (a.length() != b.length()) return a.length() < b.length();
    else {
        int sumA = 0, sumB = 0;
        for (int i = 0; i < a.length(); i++) if (isdigit(a[i])) sumA += (int(a[i] - '0'));
        for (int i = 0; i < b.length(); i++) if (isdigit(b[i])) sumB += (int(b[i] - '0'));
        
        if (sumA != sumB) return sumA < sumB;
        else {
            return a < b;
        }
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
    for (int i = 0; i < N; i++){
        cout << arr[i] << "\n";
    }
}