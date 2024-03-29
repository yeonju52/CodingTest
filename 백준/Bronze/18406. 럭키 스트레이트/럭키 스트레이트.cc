#include <iostream>

using namespace std;

int main(){
    int N;
    int fSum = 0;
    int bSum = 0;

    cin >> N;

    string s = to_string(N);
    
    if (s.length() % 2 == 0){
        int mid = s.length() / 2;

        for (int i = 0; i < mid; i++){
            fSum += int(s[i]);
            bSum += int(s[mid+i]);
        }
    }
    if (s.length() % 2 == 0 && fSum == bSum){
        cout << "LUCKY" << endl;
    }
    else {
        cout << "READY" << endl;
    }
}