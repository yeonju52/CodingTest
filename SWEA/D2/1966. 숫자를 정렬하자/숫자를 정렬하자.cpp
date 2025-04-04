#define _CRT_SECURE_NO_WARNINGS
 
#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int MAX = 50;
int N;
int arr[MAX];
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
     
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
 
        memset(arr, 0, sizeof(arr));
 
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
 
        sort(arr, arr + N); // 조건부 있는 문제 풀어보자.
 
        cout << "#" << test_case << " ";
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}