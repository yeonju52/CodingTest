#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto cmd : commands) {
        int i = cmd[0] - 1, j = cmd[1] - 1, k = cmd[2] - 1;
        vector<int> vec(array.begin() + i, array.begin() + j + 1);
        // vector<int> vec(array.begin() + i, array.begin() + j);
        // for (; i <= j; i++) {
        //     vec.push_back(array[i]);
        // }
        sort(vec.begin(), vec.end());
        answer.push_back(vec[k]);
    }
    return answer;
}