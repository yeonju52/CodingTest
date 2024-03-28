#include <iostream>

using namespace std;

int main(){
    int N;
    int cur;    
    cin >> N;
    
    int cnt = 0;
    int mini = -1;
    for (int i = 0; i <= int(N / 5); i++){
        cur = N;
        cur -= (5 * i);
        if (cur % 3 == 0){
            cnt = i + cur / 3;
            if (mini == -1 || mini > cnt){
                mini = cnt;
            }
        }
    }
    cout << mini << endl;
}