#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> set;
    for (auto ph : phone_book) {
        set.insert(ph);
    }
    
    for (auto ph : phone_book) {
        string val = "";
        for (auto p : ph) {
            val += p;
            if (set.find(val) != set.end() && val != ph) return false;
        }
    }
    return true;
}