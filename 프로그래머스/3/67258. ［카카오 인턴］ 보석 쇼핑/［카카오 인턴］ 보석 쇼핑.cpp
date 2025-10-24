#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_set<string> all_set;
    for (auto &G : gems) all_set.insert(G);
    int tar = all_set.size();
    
    unordered_map<string, int> cur;
    int cnt = 100001;
    // 투포인터로 진행
    int l = 0;
    for (int r = l; r < gems.size(); r++) {
        cur[gems[r]]++;
        while (cur.size() == tar && l <= r) {
            cur[gems[l]]--;
            if (!cur[gems[l]]) cur.erase(gems[l]);
            if (cnt > (r - l + 1)) {
                cnt = r - l + 1;
                answer = {l + 1, r + 1};
            }
            l++;
        }
    }
    return answer;
}