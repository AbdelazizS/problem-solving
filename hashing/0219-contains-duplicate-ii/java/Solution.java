import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> lastSeenIndex = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            Integer prevIndex = lastSeenIndex.get(nums[i]);
            if (prevIndex != null && i - prevIndex <= k) {
                return true;
            }
            lastSeenIndex.put(nums[i], i);
        }

        return false;
    }
}
