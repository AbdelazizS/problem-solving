import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        Map<Character, Character> forward = new HashMap<>();
        Map<Character, Character> backward = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char source = s.charAt(i);
            char target = t.charAt(i);

            if (forward.containsKey(source) && forward.get(source) != target) {
                return false;
            }
            if (backward.containsKey(target) && backward.get(target) != source) {
                return false;
            }

            forward.put(source, target);
            backward.put(target, source);
        }

        return true;
    }
}
