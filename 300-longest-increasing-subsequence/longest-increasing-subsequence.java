class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;

        int dp[] = new int[n];
        Arrays.fill(dp, 1);

        for (int i=0; i < n; i++) {
            for (int j=0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = Math.max(dp[j] + 1, dp[i]);
                }
            }
        }

        int max = dp[0];
        System.out.print(dp[0] + " ");
        for (int i=1; i < n; i++) {
            max = Math.max(max, dp[i]);
            System.out.print(dp[i] + " ");
        }

        return max;

        // int dp[][] = new int[n + 1][n + 1];

        // for (int i=1; i <= n; i++) {
        //     for (int j=1; j <= i; j++) {

        //     }
        // }

        // for (int i=1; i <= n; i++) {
        //     for (int j=1; j <= n; j++) {
        //         System.out.print(dp[i][j] + " ");
        //     }

        //     System.out.println():
        // }

    }
    static int LIS(int nums[], int idx, int last) {
        // base case
        if (idx == nums.length) return 0;
        
        // write a recurrunce

        int take = 0, notTake = 0;
        if (last == -1 || nums[last] < nums[idx]) {
            take = 1 + LIS(nums, idx + 1, idx);
        }
        notTake = LIS(nums, idx + 1, last);

        return Math.max(take, notTake);
    }
}