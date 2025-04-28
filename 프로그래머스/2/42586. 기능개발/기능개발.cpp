#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> prefix;
    int N = progresses.size(), maxi = 0;
    for (int i = 0; i < N; i++) {
        int d = (100 - progresses[i]) / speeds[i];
        d = ((100 - progresses[i]) % speeds[i] == 0) ? d : d + 1;
        maxi = max(maxi, d);
        prefix.push_back(maxi);
    }
    
    vector<int> ans;
    int prev = prefix[0], acc = 1;
    for (int i = 1; i < N; i++) {
        if (prev == prefix[i]) acc++;
        else {
            ans.push_back(acc);
            prev = prefix[i], acc = 1;
        }
    }
    if (acc != 0) ans.push_back(acc);
    return ans;
}