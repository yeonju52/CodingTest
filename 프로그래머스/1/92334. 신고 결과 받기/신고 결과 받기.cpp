#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

unordered_map<string, int> dict;

vector<set<int>> arr;
vector<int> ed_arr;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int N = id_list.size();
    for (int i = 0; i < N; i++) dict[id_list[i]] = i;
    arr.resize(N);
    ed_arr.resize(N);
    for (auto &st : report) {
        int idx = st.find(" ");
        auto &cur = arr[dict[st.substr(0, idx)]];
        int ed = dict[st.substr(idx + 1)];
        if (cur.find(ed) == cur.end()) ed_arr[ed]++;
        cur.insert(ed);
    }
    
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (auto &cur : arr[i]) {
            if (ed_arr[cur] >= k) cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}