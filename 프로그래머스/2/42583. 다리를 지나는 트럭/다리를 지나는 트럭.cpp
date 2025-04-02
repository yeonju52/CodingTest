#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    for (int i = 0; i < bridge_length; i++){
        q.push(0);
    }
    int t = 0, sum = 0, idx = 0, n = truck_weights.size();
    while(true) {
        if (sum == 0 && idx == n) break;
        t++;
        sum -= q.front();
        q.pop();
        
        if (idx < n && sum + truck_weights[idx] <= weight) {
            sum += truck_weights[idx];
            q.push(truck_weights[idx++]);
        }
        else {
            q.push(0);
        }
    }
    return t;
}