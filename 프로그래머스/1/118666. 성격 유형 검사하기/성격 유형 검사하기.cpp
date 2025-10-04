#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> scr;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int N = survey.size();
    for (int i = 0; i < N; i++) {
        auto sur = survey[i];
        int c = choices[i] - 4;
        if (c < 0) scr[sur[0]] += abs(c);
        else scr[sur[1]] += abs(c);
    }
    
    answer += (scr['T'] > scr['R'] ? 'T' : 'R');
    answer += (scr['F'] > scr['C'] ? 'F' : 'C');
    answer += (scr['M'] > scr['J'] ? 'M' : 'J');
    answer += (scr['N'] > scr['A'] ? 'N' : 'A');
    return answer;
}