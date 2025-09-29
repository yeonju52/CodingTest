#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long ans = 0;
    
    int sumD = 0, sumP = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        int cnt = 0;
        sumD += deliveries[i];
        sumP += pickups[i];
        
        while(sumD > 0 || sumP > 0)
        {
            sumD -= cap;
            sumP -= cap;
            cnt++;
        }
        ans += (i + 1) * cnt * 2;
    }
    
    
    
    return ans;
}