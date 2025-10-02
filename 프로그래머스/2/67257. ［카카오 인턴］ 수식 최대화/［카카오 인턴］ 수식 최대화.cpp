#include <bits/stdc++.h>

using namespace std;

using ll = long long;

long long calc(ll a, ll b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b;
}

long long solution(string expression) {
    vector<ll> nums;
    vector<char> ops;
    string num = "";
    
    for (char c : expression) {
        if (isdigit(c)) num += c;
        else {
            nums.push_back(stoll(num));
            ops.push_back(c);
            num = "";
        }
    }
    nums.push_back(stoll(num));
    
    long long answer = 0;
    vector<char> order({'*', '+', '-'});
    do {
        vector<ll> n = nums;
        vector<char> o = ops;
        for (auto &op : order) {
            for (int i = 0; i < o.size();) {
                if (o[i] == op) {
                    ll res = calc(n[i], n[i + 1], op);
                    n[i] = res;
                    n.erase(n.begin() + i + 1);
                    o.erase(o.begin() + i);
                }
                else {
                    i++;
                }
            }
        }
        answer = max(answer, llabs(n[0]));
    } while(next_permutation(order.begin(), order.end()));
    
    return answer;
}