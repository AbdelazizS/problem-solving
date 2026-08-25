#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastSeenIndex;

        for (int i = 0; i < (int)nums.size(); i++) {
            auto it = lastSeenIndex.find(nums[i]);
            if (it != lastSeenIndex.end() && i - it->second <= k) {
                return true;
            }
            lastSeenIndex[nums[i]] = i;
        }

        return false;
    }
};
