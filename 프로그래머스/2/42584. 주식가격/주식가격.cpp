#include <bits/stdc++.h>

using namespace std;

stack<int> st; // t
vector<int> solution(vector<int> prices) {
    vector<int> ans;
    int N = prices.size();
    ans.resize(N, 0);
    
    for (int t = 0; t < N; t++) {
        while(!st.empty() && prices[st.top()] > prices[t]) {
            ans[st.top()] = t - st.top();
            st.pop();
        }
        st.push(t);
    }
    while(!st.empty()) {
        ans[st.top()] = N - 1 - st.top();
        st.pop();
    }
    return ans;
}