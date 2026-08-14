#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> prefixSum;

public:
    NumArray(vector<int>& nums) : prefixSum(nums.size() + 1, 0) {
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};
