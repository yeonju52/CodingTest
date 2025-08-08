#include<iostream>
#include<stack>
 
using namespace std;
 
int getP(char op) {
    if (op == '+') return 1;
    if (op == '*') return 2;
    return 0;
}
 
int calc(const string &str) {
    stack<int> st;
    for (const char &c : str) {
        if (isdigit(c)) st.push(c - '0');
        else {
            int n1 = st.top(); st.pop();
            int n2 = st.top(); st.pop();
            if (c == '+') st.push(n1 + n2);
            else st.push(n1 * n2);
        }
    }
    return st.top();
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
    // cin>>T;
    T = 10;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N; cin >> N;
        string post;
        stack<int> st;
 
        while(N--) {
            char c; cin >> c;
            if (isdigit(c)) post += c;
            else if (c == ')') {
                while(st.top() != '(') {
                    post += st.top();
                    st.pop();
                }
                st.pop();
            }
            else if (c == '(') st.push(c);
            else {
                while(!st.empty() && getP(st.top()) >= getP(c)) {
                    post += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()) {
            post += st.top();
            st.pop();
        }
        cout << '#' << test_case << " " << calc(post) << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
