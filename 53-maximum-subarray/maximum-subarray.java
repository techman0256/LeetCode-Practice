class Solution {
    public int maxSubArray(int[] nums) {
        int currMax = Integer.MIN_VALUE;
        int overMax = Integer.MIN_VALUE;

        for (int i=0; i < nums.length; i++) {
            if (currMax < 0) {
                currMax = 0;
            }
            currMax += nums[i];
            overMax = Math.max(overMax, currMax);
        }
        return overMax;
    }
}