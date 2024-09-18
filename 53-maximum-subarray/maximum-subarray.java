class Solution {
    public int maxSubArray(int[] nums) {
        int currSum = 0;
        int overMax = Integer.MIN_VALUE;
        int i = 0;
        while (i < nums.length) {
            if (currSum <= 0) currSum = 0;
            
            currSum += nums[i];
            overMax = Math.max(currSum, overMax);
            i++;
        }

        return overMax;
    }
}