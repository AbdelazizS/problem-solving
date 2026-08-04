#include <array>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        array<int, 26> frequency{};

        for (string::size_type i = 0; i < s.length(); i++) {
            frequency[s[i] - 'a']++;
            frequency[t[i] - 'a']--;
        }

        for (int count : frequency) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};
