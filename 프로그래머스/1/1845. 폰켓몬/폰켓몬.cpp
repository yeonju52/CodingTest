#include <unordered_set>
#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> pocket(nums.begin(), nums.end());
    // unordered_set<int> pocket;
    // for (auto i : nums){
    //     pocket.insert(i);
    // }
    answer = min(int(nums.size() / 2), int(pocket.size()));
    return answer;
}