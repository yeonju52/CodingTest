#include <string>
#include <vector>
#include <unordered_map>
// #include <iostream>
using namespace std;

unordered_map<string, unordered_map<int, int>> preV;
unordered_map<string, unordered_map<int, int>> postV;
int wordCnt[100001];
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (auto &word : words){
        int sz = word.size();
        for (int f = 1; f < sz; f++){
            preV[word.substr(0, f)][sz]++;
            postV[word.substr(f)][sz]++;
        }
        wordCnt[sz]++;
    }
    for (auto &q : queries){
        vector<int> match;
        int sum = 0, sz = q.length(); // idx = 0;
        bool pre = (q[0] == '?' ? false : true);
        if (pre){
            int idx = q.find('?'); // while(q[++idx] != '?');
            answer.push_back(preV[q.substr(0, idx)][sz]);
        }
        else {
            int idx = q.find_last_of('?') + 1; // while(q[++idx] == '?');
            if(idx == sz) answer.push_back(wordCnt[sz]);
            else answer.push_back(postV[q.substr(idx)][sz]);

        }
    }
    return answer;
}
