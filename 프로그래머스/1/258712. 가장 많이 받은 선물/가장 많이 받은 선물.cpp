#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

unordered_map<string, int> f_dict;
vector<vector<int>> AtoB;
vector<vector<int>> stat;
vector<int> res;

int solution(vector<string> friends, vector<string> gifts) {
    int ans = 0;
    int N = friends.size();
    for (int i = 0; i < N; i++) f_dict[friends[i]] = i;
    // for (auto &f : f_dict) cout << f.first << "," << f.second << " ";
    
    AtoB.resize(N, vector<int>(N, 0));
    stat.resize(N, vector<int>(3, 0));
    for (auto &cur : gifts) {
        string A = cur.substr(0, cur.find(" "));
        string B = cur.substr(cur.find(" ") + 1);
        AtoB[f_dict[A]][f_dict[B]]++;
        stat[f_dict[A]][0]++;
        stat[f_dict[B]][1]++;
    }
    
    for (int i = 0; i < N; i++) {
        stat[i][2] = stat[i][0] - stat[i][1];
    }
    
    res.resize(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int sidx = -1, lidx = -1;
            if (AtoB[i][j] != AtoB[j][i]) { // 2(i->j) > 1(i<-j) : i <- j
                sidx = AtoB[i][j] > AtoB[j][i] ? i : j;
                lidx = sidx == i ? j : i;
            }
            else {
                if (stat[i][2] != stat[j][2]) {
                    sidx = stat[i][2] > stat[j][2] ? i : j;
                    lidx = sidx == i ? j : i;
                }
            }
            if (sidx != -1) {
                res[sidx]++;
                // cout << friends[sidx] << "<-" << friends[lidx] << "\n";
            }
        }
    }
    
    ans = *max_element(res.begin(), res.end());
    
    return ans;
    
}