#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string alpha = "AEIOU";
int base[5]; // = {781, 156, 31, 6, 1};
unordered_map<char, int> book;

void setBase(){
    int factor = 1;
    base[4] = 1;
    for (int i = 4; i >= 0; i--){
        factor *= 5;
        base[i - 1] = base[i] + factor;
    }
}

void setMap(string alpha){
    int idx = 0;
    for (char s : alpha){
        book.insert({s, idx++});
    }
}

int solution(string word) {
    // 사전 준비
    setBase(); // base 구하기 (781 156 31 6 1)
    setMap("AEIOU"); // book['A'] = 0, book['B'] = 1, ...

    int answer = 0, idx = 0;
    for (char s : word){
        answer += (book[s] * base[idx++] + 1);
    }
    return answer;
}