#include <string>
#include <vector>
#include <iostream>
using namespace std;

int compress(string s, int idx){ // 함수 목적: 압축 문자열 만들고, 길이 반환
    string comp; // 압축 문자열
    int count = 1; // 압축 개수
    int cur = 0; // 현 탐색 위치(index)
    
    while(true){ 
        if(s.length() < cur + idx) { // 종료 조건 
            comp += s.substr(cur, s.length() - cur);
            return comp.length();
        };
        
        string peek = s.substr(cur, idx); // 기준 문자열
        string next = s.substr(cur + idx, idx); // 비교 문자열
        if(peek != next) {
            if(count != 1) { comp += to_string(count); }
            comp += peek;
            count = 1;
        }
        else { count++; }
        
        cur += idx;
    }
} // 함수 쓸 때, *주의*: testing 할 때, 함수 반환 값 없으면 에러 뜸.

int solution(string s) {
    int answer = 0;

    //최소값 찾기
    int mini = 1000;
    for(int i = 1; i <= s.length()/2; i++) {
        int temp = compress(s, i);
        if(mini > temp) { mini = temp; }
    }
    if(s.length() == 1) { mini = 1; } // 예외사항
    
    answer = mini;
    return answer;
}