#include <iostream>
#include <cctype>
using namespace std;

int main(){
    int lenAlpha = 'z' - 'a' + 1;
    string s;

    getline(cin, s);

    for (int i = 0; i < s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = (s[i] - 'a' + 13) % lenAlpha + 'a';
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = (s[i] - 'A' + 13) % lenAlpha + 'A';
        }
    }
    cout << s << endl;
}