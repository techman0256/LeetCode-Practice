class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;

        int dp[][] = new int[n][2];
        for (int i=0; i < n; i++) {
            for (int j=0; j < 2; j++) {
                dp[i][j] = Integer.MIN_VALUE;
            }
        }
        // Base Case
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        

        for (int i=1; i < n; i++) {
            for (int j=0; j < 2; j++) {
                int buy = 0, sell = 0, hold = 0;
                if (j == 0) {
                    buy = -prices[i];
                } else {
                    sell = prices[i] + dp[i - 1][0]; 
                }
                hold = dp[i - 1][j];
                dp[i][j] = Math.max(hold, buy + sell);
            }
        }
        System.out.println(dp[n - 1][1]);
        if (dp[n - 1][1] < 0) {
            return 0;
        }
        return dp[n - 1][1];
        // return fx(0, 0, prices);
    }
    
    static int fx(int idx, int flag, int prices[]) {
        if (idx == prices.length) {
            return 0;
        }
        int buy = 0, sell = 0, hold = 0;
        hold = fx(idx + 1, flag, prices);
        if (flag == 0) {
            buy = -prices[idx] + fx(idx + 1, 1, prices);
        } else {
            sell = prices[idx];
        }
       
        return Math.max(hold, buy + sell);
    }

}