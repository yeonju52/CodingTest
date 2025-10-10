#include <bits/stdc++.h>

using namespace std;

int solution(int coin, vector<int> cards) {
    int ans = 1;
    int N = cards.size(), tar = cards.size() + 1;;
    unordered_set<int> arr(cards.begin(), cards.begin() + N / 3);
    
    unordered_set<int> suspend;
    for (int i = N / 3; i < N; i+= 2) {
        int b1 = cards[i], b2 = cards[i+1];
        suspend.insert(b1); suspend.insert(b2);
        
        bool made = false;
        for (int a : arr) {
            if (arr.count(tar - a)) {
                arr.erase(a);
                arr.erase(tar - a);
                ans++;
                made = true;
                break;
            }
        }
        if (made) continue;
        
        if (coin >= 1) {
            for (int a : arr) {
                if (suspend.count(tar - a)) {
                    arr.erase(a);
                    suspend.erase(tar - a);
                    coin--;
                    ans++;
                    made = true;
                    break;
                }
            }
        }
        if (made) continue;
        
        if (coin >= 2) {
            for (int a : suspend) {
                if (suspend.count(tar - a)) {
                    suspend.erase(a);
                    suspend.erase(tar - a);
                    coin -= 2;
                    ans++;
                    made = true;
                    break;
                }
            }
        }
        if (made) continue;
        
        break;
    }
    return ans;
}