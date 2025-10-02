#include <bits/stdc++.h>

using namespace std;

unordered_map<string, pair<int, int>> dict = {{"zer", {0, 4}}, {"one", {1, 3}},
                                              {"two", {2, 3}}, {"thr", {3, 5}},
                                              {"fou", {4, 4}}, {"fiv", {5, 4}},
                                              {"six", {6, 3}}, {"sev", {7, 5}},
                                              {"eig", {8, 5}}, {"nin", {9, 4}}};

int solution(string s) {
    int answer = 0;
    auto iter = s.begin();
    while(iter != s.end()) {
        answer *= 10;
        int L = 1;
        if (isdigit(*iter)) answer += (*iter - '0');
        else {
            auto [n, l] = dict[string(iter, iter + 3)];
            answer += n, L = l;
        }
        iter += L;
    }
    return answer;
}