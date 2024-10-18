#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int llen = 0, slen = 0;
    for (auto& xy : sizes){
        if (xy[0] > xy[1]) llen = max(xy[0], llen), slen = max(xy[1], slen);
        else llen = max(xy[1], llen), slen = max(xy[0], slen);
    }
    answer = llen * slen;
    return answer;
}