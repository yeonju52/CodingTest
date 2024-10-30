#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long start = 1, end = (long long)*max_element(times.begin(), times.end()) * (long long)n;
    long long answer = (long long)*max_element(times.begin(), times.end()) * (long long)n;;
    
    while (start <= end){
        long long mid = (start + end) / 2;
        long long cnt = 0;
        for (int t : times){
            cnt += (mid / t);
        }
        if (cnt >= n){
            answer = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return answer;
}