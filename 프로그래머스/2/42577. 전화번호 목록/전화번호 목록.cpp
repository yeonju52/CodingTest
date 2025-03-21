#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> books;
    sort(phone_book.begin(), phone_book.end());
    for (auto ps : phone_book) {
        string b = "";
        for (auto p : ps) {
            b += p;
            if (books.find(b) != books.end()) return false;
        }
        books.insert(ps);
        
    }
    return true;
}