class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;

        int dp[][] = new int[n][2];
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i=1; i < n; i++) {
            for (int j=0; j < 2; j++) {
                int buy = 0, sell = 0, hold = 0;
                if (j == 0) {
                    buy = -prices[i] + dp[i - 1][1];
                } else {
                    sell = prices[i] + dp[i - 1][0];
                }
                hold = dp[i - 1][j];
                dp[i][j] = Math.max(hold, sell + buy);
            }
        }

        return dp[n - 1][1];

    }
}