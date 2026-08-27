#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];

            while (window.count(c)) {
                window.erase(s[left]);
                left++;
            }

            window.insert(c);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
