#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b){
    if (a.first == b.first){
        if (a.second < b.second) return true;
    }
    else if (a.first > b.first) return true;
    return false;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int, int>> > record;
    vector<pair<int, string> > sumR;
    for (int i = 0; i < genres.size(); i++){
        record[genres[i]].push_back({plays[i], i});
    }
    for (auto& arec : record){
        int sumi = 0;
        for (auto& p : arec.second) {
            sumi += p.first;
        }
        sumR.push_back({sumi, arec.first});
    }
    
    sort(sumR.begin(), sumR.end(), greater<pair<int, string>>());
    for (auto agen : sumR){
        auto arec = record[agen.second];
        sort(arec.begin(), arec.end(), cmp);
        int idx = 0;
        for (auto id : arec){
            if (idx++ == 2) break;
            answer.push_back(id.second);
        }
    }
    return answer;
}