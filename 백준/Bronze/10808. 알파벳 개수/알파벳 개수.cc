#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "baekjoon";
    getline(cin, s);

    vector<int> alpha(122 - 97 + 1, 0);
    for (char c: s){
        alpha[c - 97]++;
    }

    for (int i: alpha){
        cout << i << " ";
    }
}