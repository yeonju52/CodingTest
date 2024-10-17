#include <unordered_set>
#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> pocket;
    int answer = 0;
    for (auto i : nums){
        pocket.insert(i);
    }
    answer = min(int(nums.size() / 2), int(pocket.size()));
    return answer;
}