#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long ans = 0;
    
    while(!deliveries.empty() && deliveries.back() == 0) deliveries.pop_back();
    while(!pickups.empty() && pickups.back() == 0) pickups.pop_back();
    
    while(!deliveries.empty() || !pickups.empty()) {
        ans += (max(deliveries.size(), pickups.size())) * 2;
        int sumD = 0, sumP = 0;
        while(!deliveries.empty()) {
            sumD += deliveries.back();
            deliveries.pop_back();
            if (sumD > cap) {
                deliveries.push_back(sumD - cap);
                break;
            }
        }
        while(!pickups.empty()) {
            sumP += pickups.back();
            pickups.pop_back();
            if (sumP > cap) {
                pickups.push_back(sumP - cap);
                break;
            }
        }
    }    
    
    return ans;
}