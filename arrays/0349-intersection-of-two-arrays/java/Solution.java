import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        List<Integer> intersection = new ArrayList<>();
        int first = 0;
        int second = 0;

        while (first < nums1.length && second < nums2.length) {
            if (nums1[first] == nums2[second]) {
                if (intersection.isEmpty()
                        || intersection.get(intersection.size() - 1) != nums1[first]) {
                    intersection.add(nums1[first]);
                }
                first++;
                second++;
            } else if (nums1[first] < nums2[second]) {
                first++;
            } else {
                second++;
            }
        }

        return intersection.stream().mapToInt(Integer::intValue).toArray();
    }
}
