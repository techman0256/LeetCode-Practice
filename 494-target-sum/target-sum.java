class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        int m = target;
        int dp[][] = new int[n][4001];

        for (int i=0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }

        return ways(nums, nums.length -1, target, dp);
    }
    static int ways(int[] nums, int idx, int target, int memo[][]) {
        if (target == 0 && idx < 0) return 1;
        else if (idx < 0) return 0;
        
        if (memo[idx][target + 2000] != -1) {
            return memo[idx][target + 2000];
        }

        int pos = ways(nums, idx - 1, target - nums[idx], memo);
        int neg = ways(nums, idx - 1, target + nums[idx], memo);

        return memo[idx][target + 2000] = pos + neg;
    }
}