class Solution {
    long rec(int idx, int[] nums, long dp[]) {
        int n = nums.length;
        if (idx == n) {
            return 0;
        }

        if (dp[idx] != Long.MIN_VALUE) {
            return dp[idx];
        }
        long maxi = Long.MIN_VALUE;
        long cost = 0;


        for (int k=idx; k < n; k++) {
            cost += Math.pow(-1, k - idx) * nums[k];
            long rem = rec(k + 1, nums, dp);
            maxi = Math.max(rem + cost, maxi);
        }

        return dp[idx] = maxi;
    }
    public long maximumTotalCost(int[] nums) {
        long[] dp = {0, nums[0], 0};
        for (int i = 1; i < nums.length; ++i) {
            dp[(i + 1) % 3] = Math.max(dp[i % 3] + nums[i], dp[(i - 1) % 3] + nums[i - 1] - nums[i]);
        }
        return dp[nums.length % 3];
    }
}