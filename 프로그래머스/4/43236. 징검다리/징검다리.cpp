#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    long long st = 0, ed = distance;
    
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    while (st <= ed) {
        long long mid = (st + ed) / 2;
        
        int cur = 0, cnt = 0;
        
        for (int r : rocks) {
            if (r - cur >= mid) {
                cur = r;
            }
            else {
                cnt++;
            }
        }
        
        if (cnt <= n) {
            st = mid + 1;
            answer = mid;
        }
        else {
            ed = mid - 1;
        }
    }
    return answer;
}