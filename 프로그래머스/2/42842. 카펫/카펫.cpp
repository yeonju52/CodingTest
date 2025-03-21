#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sumOfab = (brown - 4) / 2;
    for (int a = 1; a <= sumOfab / 2 ; a++) {
        if (a * (sumOfab - a) == yellow) {
            answer.push_back(sumOfab - a + 2);
            answer.push_back(a + 2);
            break;
        }
    }
    return answer;
}