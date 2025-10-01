#include <bits/stdc++.h>

using namespace std;

map<string, int> dict;
vector<int> time_table; // IN일 때만
vector<int> sumT; // IN일 때만

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for (auto &R : records) {
        int T = stoi(R.substr(0, 2)) * 60 + stoi(R.substr(3, 2));
        string car = R.substr(6, 4);
        if (R.size() == 13) { // IN
            if (dict.find(car) == dict.end()) { // 새로운 차일 때,
                dict[car] = time_table.size();
                time_table.push_back(T);
                sumT.push_back(0);
            }
            else { // 원래 있던 차일 때,
                int idx = dict[car];
                time_table[idx] = T;
            }
        }
        else { // OUT
            int idx = dict[car];
            sumT[idx] += (T - time_table[idx]);
            time_table[idx] = -1;
        }
    }
    for (auto &cur : dict) {
        int idx = cur.second;
        if (time_table[idx] > -1) sumT[idx] += (23 * 60 + 59 - time_table[idx]);
    }
    
    for (auto &cur : dict) {
        int T = sumT[cur.second], res = 0;
        if (T > fees[0]) {
            res += (T - fees[0]) / fees[2] * fees[3];
            if ((T - fees[0]) % fees[2]) res += fees[3];
        }
        res += fees[1];
        answer.push_back(res);
    }
    return answer;
}