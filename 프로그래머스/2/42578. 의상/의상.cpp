#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, vector<string>> dress;
    
    for (auto &cloth : clothes){
        dress[cloth[1]].push_back(cloth[0]);
    }
    for (auto &comb : dress){
        answer *= int(comb.second.size() + 1);
    }
    
    return answer - 1; // 공집합 제거
}