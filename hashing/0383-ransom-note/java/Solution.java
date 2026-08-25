import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> counts = new HashMap<>();

        for (char c : magazine.toCharArray()) {
            counts.merge(c, 1, Integer::sum);
        }

        for (char c : ransomNote.toCharArray()) {
            int remaining = counts.getOrDefault(c, 0);
            if (remaining == 0) return false;
            counts.put(c, remaining - 1);
        }

        return true;
    }
}
