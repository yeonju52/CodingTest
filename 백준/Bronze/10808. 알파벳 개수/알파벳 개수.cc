#include <iostream>
using namespace std;

int arr[26]; // int len = 'z' - 'a' + 1; cout << len << "\n";
    
int main() {
    string s; cin >> s;
    for (char& c : s) {
        arr[c - 'a']++;
    }
    for (int &i : arr) {
        cout << i << " ";
    }
}