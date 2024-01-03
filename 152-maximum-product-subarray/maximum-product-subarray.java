class Solution {
    public int maxProduct(int[] nums) {
        int overMax = Integer.MIN_VALUE;
        int currProd = 1;
        int minProd = 1;

        for (int i=0; i < nums.length; i++) {
            // currProd = Math.min(Math.max)
            int temp = Math.max(Math.max(nums[i] * currProd, nums[i] * minProd), nums[i]);
            minProd = Math.min(Math.min(nums[i] * currProd, nums[i] * minProd), nums[i]);
            currProd = temp;
            overMax = Math.max(currProd, overMax);
        }
        return overMax;
    }
}