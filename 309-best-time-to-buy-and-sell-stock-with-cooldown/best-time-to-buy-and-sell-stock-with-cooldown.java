class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int dp[][] = new int[n + 1][3];
        for (int i=0; i <=n; i++) {
            Arrays.fill(dp[i], - 1);
        }

        return fx(0, 0, prices, dp);
    } 
    static int fx(int idx, int flag, int prices[], int dp[][]) {
        if (idx == prices.length) return 0;
        // System.out.println(flag);
        if (dp[idx][flag] != -1) {
            return dp[idx][flag];
        }

        // int buy = 0, sell = 0, hold = 0;
        int transact = 0;
        if (flag == 0 ) {
            transact = Math.max(-prices[idx] + fx(idx + 1, 1, prices, dp), fx(idx + 1, flag, prices, dp));
        } else if (flag == 1) {
            transact = Math.max(prices[idx] + fx(idx + 1, 2, prices, dp), fx(idx + 1, flag, prices, dp));
        } else if (flag == 2) {
            // flag = 0;
            transact = fx(idx + 1, 0, prices, dp);
            
        }

        return dp[idx][flag] = transact;


    }
}