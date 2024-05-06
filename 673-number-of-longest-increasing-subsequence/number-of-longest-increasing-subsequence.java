class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;

        int dp[] = new int[n];
        int noi[] = new int[n];
        Arrays.fill(dp, 1);
        // Arrays.fill(noi, 1);

        for (int i=0; i < n; i++) {
            for (int j=0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] == 1) {
                noi[i] = 1;
            } else {
                for (int j=0; j < i; j++) {
                    if (nums[j] < nums[i] && dp[j] == dp[i] - 1) noi[i] += noi[j];
                }
            }
        }

        int max = dp[0];
        for (int i=1; i < n; i++) {
            max = Math.max(dp[i], max);
        }
        
        int count = 0;
        for (int i=0; i < n; i++) {
            if (max == dp[i]) count += noi[i];
        }
        // System.out.println(Arrays.toString(noi));
        // System.out.println(Arrays.toString(dp));
        // return noi[max];
        return count;
    }
}