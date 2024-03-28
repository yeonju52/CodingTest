#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    int st, ed;
    int cnt = 0;
    int start_time = 0;

    cin >> N;
    vector<vector<int>> arr(N);

    for (int i = 0; i < N; i++){
        cin >> st >> ed;
        arr[i] = {ed, st};
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < N; i++){
        if (arr[i][1] >= start_time){
            start_time = arr[i][0];
            cnt++;
        }
    }
    cout << cnt << endl;
}