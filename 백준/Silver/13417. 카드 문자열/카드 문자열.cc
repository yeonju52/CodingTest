#include <bits/stdc++.h>
using namespace std;

int N, T;
string card, ans;

void dfs(string mak, int idx){
    if (idx == N) {
        if(ans.empty() || ans > mak) ans = mak;
        return ;
    } // DAS vs ASD
    if (mak.empty() || (mak + card[idx] < card[idx] + mak)) dfs(mak + card[idx], idx + 1);
    else dfs(card[idx] + mak, idx + 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        card = "", ans = ""; // 매 턴마다 초기화
        cin >> N;
        for (int i = 0; i < N; i++){
            char c; cin >> c;
            card.push_back(c);
        }
        dfs("", 0);
        cout << ans << "\n";
    }
}