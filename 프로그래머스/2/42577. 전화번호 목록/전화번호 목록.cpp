#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_multiset<string> f_book; // (phone_book.begin(), phone_book.end());
    for (string num : phone_book){
        string prefix = "";
        for(char c : num){
            prefix += c;
            f_book.insert(prefix);
        }
    }
    for (string num : phone_book){
        f_book.erase(f_book.find(num));
        if (f_book.find(num) != f_book.end()) return false;
    }
    return true;
}