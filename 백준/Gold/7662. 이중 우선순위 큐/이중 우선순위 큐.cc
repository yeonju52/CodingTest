#include <bits/stdc++.h>
using namespace std;

int T, N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T--) {
        multiset<int> heap; // 최소힙
    
        cin >> N;
        while(N--) {
            char cmd;
            int v;
            cin >> cmd >> v;
            if (cmd == 'I') heap.insert(v);
            else {
                if (heap.empty()) continue;
                if (v == 1) {
                    heap.erase(--heap.end());
                }
                else {
                    heap.erase(heap.begin());
                }
            }
        }
        if (heap.empty()) cout << "EMPTY\n";
        else cout << *heap.rbegin() << " " << *heap.begin() << "\n";
    }
}