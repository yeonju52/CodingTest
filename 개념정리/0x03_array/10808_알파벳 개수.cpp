#include <bits/stdc++.h>
using namespace std;

int alpha[26];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;    // getline(cin, s);

    // vector<int> alpha(122 - 97 + 1, 0);
    for (char c: s){
        alpha[c - 'a']++;
    }

    for (int i = 0; i < 26; i++){
        cout << alpha[i] << " ";
    }
}