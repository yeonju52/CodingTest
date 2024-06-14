#include <iostream>
#include <vector>
using namespace std;

int N, S;
int cnt = 0;

void recursion(int idx, vector<int> subArr, int sum){
    sum += subArr[idx];
    // subArr.erase(subArr.begin() + idx); // permutation: 순열
    subArr.erase(subArr.begin(), subArr.begin() + idx + 1);
    
    if (sum == S){
        cnt++;
        return ;
    }
    for (int i = 0; i < subArr.size(); i++){
        recursion(i, subArr, sum);
    }
}

int main(){

    cin >> N >> S;

    vector<int> arr(N, 0);

    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++){
        recursion(i, arr, 0);
    }

    cout << cnt;
}
