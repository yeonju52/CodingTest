#include <string>
#include <unordered_set>
#include <cmath>
#include <iostream>

using namespace std;

unordered_set<int> vec;

void comb(string num, string others) {
    if (num != "") vec.insert(stoi(num));
    for (int i = 0; i < others.size(); i++) {
        comb(num + others[i], others.substr(0, i) + others.substr(i + 1));
    }
}

bool isPrime(int n) {
    if (n == 0 || n == 1) return false;
    int N = sqrt(n);
    for (int i = 2; i <= N; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    comb("", numbers);
    for (int v : vec) {
        if (isPrime(v)) answer++;
    }
    return answer;
}