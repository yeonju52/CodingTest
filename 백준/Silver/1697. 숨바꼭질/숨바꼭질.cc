#include<bits/stdc++.h>
using namespace std;

int N, K;
int ndist[100002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fill(ndist, ndist + 100002, -1);
    
    cin >> N >> K;
    queue<int> nQ; nQ.push(N); ndist[N] = 0;
    
    while(!nQ.empty()){
        int n = nQ.front(); nQ.pop();
        if (n == K) {
            cout << ndist[n] << '\n';
            return 0;
        }
        int nn[3] = {n + 1, n - 1, n * 2};
        for (int i = 0; i < 3; i++){
            if (nn[i] < 0 || nn[i] > 100000 || ndist[nn[i]] >= 0) continue;
            ndist[nn[i]] = ndist[n] + 1; nQ.push(nn[i]);
        }
    }
    return 0;
}