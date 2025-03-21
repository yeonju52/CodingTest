#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    
    for (auto input : s) {
        if (input == ')') {
            if (!st.empty() && st.top() == '(') st.pop();
            else {
                answer = false;
                break;
            }
        }
        else {
            st.push('(');
        }
    }
    
    if (!st.empty()) answer = false;
    return answer;
}