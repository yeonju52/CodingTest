#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
    // int slen = name.size();
    int sum = 0;
    // 알파벳 개수 25개 ('Z' - 'A')
    for (int i = 0; i < name.size(); i++){
        int tmp = name[i] - 'A';
        sum += min(tmp, 26 - tmp);
    }
    // 커서 움직이기
    int len = name.size();
    int move = len - 1;
    for (int i = 0; i < len; i++) {
        // i에서 연속된 A 구간을 넘어가는 방법을 계산
        int next = i + 1;
        while (next < len && name[next] == 'A') {
            next++;
        }
        // move는 0에서 오른쪽으로 쭉 가는 경우이고,
        // i + len - next + i 는 A를 만날때까지 오른쪽으로 갔다가 A를 만나면 왼쪽으로 가는 경우
        // i + len - next + len - next 는 처음부터 왼쪽으로 갔다가 A를 만나면 오른쪽으로 가는 경우
        move = min(move, i + len - next + min(i, len - next));
    }
    
    sum += move;
    return sum;
}