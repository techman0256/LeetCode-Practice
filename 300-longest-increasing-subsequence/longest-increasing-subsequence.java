class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int dp[][] = new int[n + 1][n + 1];

        for (int i=0; i < n + 1; i++) {
            Arrays.fill(dp[i], -1);
        }

        return LIS(nums, 0, -1, dp);
    }
    static int LIS(int nums[], int idx, int last, int dp[][]) {
        if (idx >= nums.length) return 0;
        if (dp[idx + 1][last + 1] != -1) {
            return dp[idx + 1][last + 1];
        }

        int take = 0;
        if (last == -1 || nums[last] < nums[idx]) {
            take = 1 + LIS(nums, idx + 1, idx, dp);
        }
        int notTake = LIS(nums, idx + 1, last, dp);
        
        return dp[idx + 1][last + 1] = Math.max(take, notTake);
    }
}