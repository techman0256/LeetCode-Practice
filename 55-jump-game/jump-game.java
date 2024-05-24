class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;

        boolean dp[] = new boolean[n];
        Arrays.fill(dp, false);
        dp[n - 1] = true;
        for (int i = n - 2; i >=0; i--) {
            boolean canJump = false;
            for (int j=i + 1; j <= i + nums[i]; j++) {
                canJump = canJump || dp[j];
            }
            dp[i] = canJump;
        }

        return dp[0];
    }
}
