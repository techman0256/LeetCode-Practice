class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;

        int dp[][] = new int[n + 1][n + 1];
        for (int i=0; i <= n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return fx(0, -1, nums, dp);
    }
    static int fx(int idx, int last, int nums[], int dp[][]) {
        if (idx == nums.length) {
            return 0;
        }

        if (dp[idx][last + 1] != -1) {
            return dp[idx][last + 1];
        }

        int take = 0;
        if (last == -1 || nums[idx] > nums[last]) {
            take = 1 + fx(idx + 1, idx, nums, dp);
        }
        
        int notTake = fx(idx + 1, last, nums, dp);

        return dp[idx][last + 1] = Math.max(take, notTake);
    }
}