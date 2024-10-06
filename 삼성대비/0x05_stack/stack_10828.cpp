#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;

    int N; cin >> N;
    
    // for (int i = 0; i < N; i++){
    while(N--){
        string s;
        cin >> s;
        if (s == "push"){
            int X; cin >> X;
            st.push(X);
            // cin.clear();
        }
        else if (s == "pop"){
            if (!st.empty()) {
                cout << st.top() << '\n';
                st.pop();
            }
            else cout << -1 << '\n';
        }
        else if (s == "size") cout << st.size() << '\n';
        else if (s == "empty"){
            if (!st.empty()) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else if (s == "top"){
            if (!st.empty()) cout << st.top() << '\n';
            else cout << -1 << '\n';
        }
    }

}