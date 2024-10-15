// 코딩테스트 연습 > 정렬 > 가장 큰 수 (lv2)
#include <string>
#include <vector>
// #include <iostream>
#include <algorithm>
using namespace std;

pair<string, string> num_str[100001];
int N, zeroN;

bool cmp(pair<string, string> &a, pair<string, string> &b){
    if (a.first > b.first) return 1;
    return 0;
}


string solution(vector<int> numbers) {
    string answer = "";
    
    string s, snum;
    int len = numbers.size(), idx = 0;
    for (int i = 0; i < len; i++){
        snum = "", s = to_string(numbers[i]), N = s.size();
        if (s == "0") { zeroN++; continue; }
        for (int j = 0; j < 5 - N; j++) snum += s; // s * 3
        snum = snum.substr(0, 4);
        num_str[idx++] = {snum, to_string(numbers[i])};
    }
    
    sort(num_str, num_str + idx);
    while (idx--) answer += num_str[idx].second;

    if (answer == "") answer = "0"; // 모두 0인 경우, 
    else {
        while (zeroN--) answer += "0";
    }
    return answer;
}