#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> forward;
        unordered_map<char, char> backward;

        for (size_t i = 0; i < s.length(); i++) {
            char source = s[i];
            char target = t[i];

            if (forward.count(source) && forward[source] != target) {
                return false;
            }
            if (backward.count(target) && backward[target] != source) {
                return false;
            }

            forward[source] = target;
            backward[target] = source;
        }

        return true;
    }
};
