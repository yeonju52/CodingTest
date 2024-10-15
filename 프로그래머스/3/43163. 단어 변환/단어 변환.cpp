#include <string>
#include <vector>
#include <iostream>
using namespace std;

int initSz = 0;
int minCnt = 51;

bool isOK(string cur, string tar){
    int diff = 0;
    int len = cur.size();
    for (int i = 0; i < len; i++){
        if (cur[i] != tar[i]) diff++;
    }
    if (diff == 1) return 1;
    return 0;
}
void dfs(int idx, string tar, vector<string> words){
    string cur = words[idx];
    if (cur == tar) {
        minCnt = min(minCnt, initSz - int(words.size()) + 1);
        return ;
    }
    words.erase(words.begin() + idx);  

    for (int i = 0; i < words.size(); i++){
        if (isOK(cur, words[i])) {
            dfs(i, tar, words);
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    initSz = words.size();
    for (int i = 0; i < words.size(); i++){
        if (isOK(begin, words[i])){
            dfs(i, target, words);            
        }
    }
    answer = minCnt;
    if (answer == 51) answer = 0;
    return answer;
}