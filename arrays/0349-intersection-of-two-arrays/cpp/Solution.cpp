#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        size_t first = 0;
        size_t second = 0;

        while (first < nums1.size() && second < nums2.size()) {
            if (nums1[first] == nums2[second]) {
                if (result.empty() || result.back() != nums1[first]) {
                    result.push_back(nums1[first]);
                }
                first++;
                second++;
            } else if (nums1[first] < nums2[second]) {
                first++;
            } else {
                second++;
            }
        }

        return result;
    }
};
