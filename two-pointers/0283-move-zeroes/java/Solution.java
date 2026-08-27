class Solution {
    public void moveZeroes(int[] nums) {
        int writePos = 0;

        for (int readPos = 0; readPos < nums.length; readPos++) {
            if (nums[readPos] != 0) {
                int temp = nums[writePos];
                nums[writePos] = nums[readPos];
                nums[readPos] = temp;
                writePos++;
            }
        }
    }
}
