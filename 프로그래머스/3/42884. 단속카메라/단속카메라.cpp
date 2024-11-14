#include<iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int prev = routes[0][1];
    for (auto r : routes) {
        if (prev < r[0]) { prev = r[1]; answer++; }
        else { prev = min(prev, r[1]); }
    }
    return answer;
}