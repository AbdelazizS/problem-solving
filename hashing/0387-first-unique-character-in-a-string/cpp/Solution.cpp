#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> counts;

        for (char c : s) {
            counts[c]++;
        }

        for (int i = 0; i < (int)s.size(); i++) {
            if (counts[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
