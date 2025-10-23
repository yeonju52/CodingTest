#include <bits/stdc++.h>

using namespace std;

int solution(int balls, int share) {
    int K =  min(balls - share, share);
    long long mul = 1, div = 1;
    for (int k = 0; k < K; k++) {
        mul *= (balls - k), div *= (k + 1);
        int g = gcd(mul, div);
        mul /= g, div /= g;
    }
    return (mul / div);
}