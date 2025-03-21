#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> book;
    
    for (auto p : participant){
        book[p]++;
    }
    
    for (auto p : completion){
        book[p]--;
    }
    
    for (auto p : book) {
        if (p.second > 0){
            answer = p.first;
            break;
        }
    }
    return answer;
}