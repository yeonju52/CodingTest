#include <iostream>
#include <vector>
using namespace std;

int cnt;
void recursion(int sum, int target){
    if (sum >= target){
        if (sum == target){
            cnt++;
        }
        return ;
    }
    for (int i = 1; i <= 3; i++){
        recursion(sum + i, target);
    }

}

int main(){
    int N;
    int k;

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> k;
        cnt = 0;
        recursion(0, k);
        cout << cnt << endl;
    }
}