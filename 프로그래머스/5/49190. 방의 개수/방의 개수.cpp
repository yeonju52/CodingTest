#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

using P = pair<int, int>;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int solution(vector<int> arrows) {
    int ans = 0;
    
    set<P> v;
    set<pair<P, P>> e;
    
    int x = 0, y = 0;
    v.insert({x, y});
    
    for (auto &i : arrows) {
        for (int t = 0; t < 2; t++) {
            int nx = x + dx[i], ny = y + dy[i];
            
            P cur = {x, y}, nxt = {nx, ny};
            if(e.find({cur, nxt}) == e.end()) {
                if (v.find(nxt) != v.end()) {
                    ans++;
                }
            }
            
            e.insert({cur, nxt}), e.insert({nxt, cur});
            v.insert(nxt);
            
            x = nx, y = ny;
        }
    }
    
    
    return ans;
}