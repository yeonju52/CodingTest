#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string s;
    int N;
    char tar;
    int st, en;
    int cnt;

    getline(cin, s);
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> tar >> st >> en;
        cnt = 0;
        for (int i = st; i <= en; i++){
            if (s[i] == tar){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}