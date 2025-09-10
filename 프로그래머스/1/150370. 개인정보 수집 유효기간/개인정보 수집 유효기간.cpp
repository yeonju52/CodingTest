#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> dict;

struct unit {
    int y, m, d;
};

unit s2unit (string s) {
    return {stoi(s.substr(0, 4)), stoi(s.substr(5, 2)), stoi(s.substr(8, 2))};
}

unit sumM(unit cur, int valid_m) { // [12, 28]
    cur.d--;
    if (cur.d == 0) cur.d = 28, cur.m--;
    if (cur.m == 0) cur.y--;
    cur.m += valid_m;
    cur.y += (cur.m - 1) / 12;
    cur.m = (cur.m - 1) % 12 + 1; // 12월 -> 0월로 표시될 수 있음
    return cur;
}

bool dump(unit tar, unit cur) {
    if (tar.y != cur.y) return tar.y < cur.y;
    if (tar.m != cur.m) return tar.m < cur.m;
    return tar.d < cur.d; // 같으면 파기하지 않는다. -> 다르면 파기한다
}
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> ans;
    unit cur = s2unit(today);
    // cout << cur.y << "," << cur.m << "," << cur.d << "\n";
    for (auto &t : terms) {
        dict[t[0]] = stoi(t.substr(2));
    }
    
    int plen = privacies.size();
    for (int i = 1; i <= plen; i++) {
        auto &p = privacies[i-1];
        unit tar = sumM(s2unit(p.substr(0, 10)), dict[p[11]]);
        if(dump(tar, cur)) ans.push_back(i);
        // cout << other.y << "," << other.m << "," << other.d << "\n";
    }
    return ans;
}