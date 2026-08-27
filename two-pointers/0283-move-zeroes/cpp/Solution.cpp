#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int writePos = 0;

        for (int readPos = 0; readPos < (int)nums.size(); readPos++) {
            if (nums[readPos] != 0) {
                swap(nums[writePos], nums[readPos]);
                writePos++;
            }
        }
    }
};
