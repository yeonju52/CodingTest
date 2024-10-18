#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

string docs = "AEIOU"; // 0 1 2 3 4
unordered_map<char, int> docs_map;
int pos[5];

int solution(string word) {
    int answer = 0;
    for (int i = 0; i < 5; i++) docs_map[docs[i]] = i; // 'A': 0
    pos[4] = 1; // pos = { 781 156 31 6 1 }
    for (int i = 3; i >= 0; i--) pos[i] = pos[i + 1] * 5;
    for (int i = 3; i >= 0; i--) pos[i] += pos[i + 1];
    int idx =  0;
    for (auto& s : word) {
        answer += (docs_map[s] * pos[idx++] + 1);
    }
    return answer;
}