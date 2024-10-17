#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> part(participant.begin(), participant.end());
    for (auto name : completion){
        part.erase(part.find(name));
    }
    answer = *part.begin();
    return answer;
}