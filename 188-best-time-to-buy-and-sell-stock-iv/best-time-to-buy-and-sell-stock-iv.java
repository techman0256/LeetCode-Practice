class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        
        int dp[][][] = new int[n + 1][2][k + 1];
        // for (int i=0; i <= n; i++) {
        //     for (int j=0; j < 2; j++) {
        //         Arrays.fill(dp[i][j], -1);
        //     }
        // }
        // // Base Case
        // for (int i=1; i <= k; i++) {
        //     dp[0][0][i] = -prices[0];
        // } 
        
        // for (int i=1; i <= n; i++) {
        //     for (int j=0; j < 2; j++) {
        //         for (int l = 1; l <= k; l++) {
        //             int buy = 0, sell = 0, hold = 0;
        //             // System.out.println(i);
        //             if (j == 0) {
        //                 buy = -prices[i - 1] + dp[i - 1][1][l];
        //             } else {
        //                 sell = prices[i - 1] + dp[i - 1][0][l - 1];
        //             }
        //             hold = dp[i - 1][j][l];
        //             dp[i][j][l] = Math.max(hold, sell + buy);
        //         }
        //     }
        // }

        for (int i=n - 1; i >= 0; i--) {
            for (int j=0; j < 2; j++) {
                for (int l = 1; l <= k; l++) {
                    int buy = 0, sell = 0, hold = 0;
                    System.out.println(i);
                    if (j == 0) {
                        buy = -prices[i] + dp[i + 1][1][l];
                    } else {
                        sell = prices[i] + dp[i + 1][0][l - 1];
                    }
                    hold = dp[i + 1][j][l];
                    dp[i][j][l] = Math.max(hold, sell + buy);
                }
            }
        }

        return dp[0][0][k];
        // return fx(0, 0, k, prices, dp);
        
    }
    static int fx(int idx, int flag, int count, int prices[], int dp[][][]) {
        if (idx == prices.length || count == 0) {
            return 0;
        }
        
        if (dp[idx][flag][count] != -1) {
            return dp[idx][flag][count];
        }


        int buy = 0, sell = 0, hold = 0;
        if (flag == 0) {
            buy = -prices[idx] + fx(idx + 1, 1, count, prices, dp); 
        } else {
            sell = prices[idx] + fx(idx + 1, 0, count - 1, prices, dp);
        }

        hold = fx(idx + 1, flag, count, prices, dp);
         
        return dp[idx][flag][count] = Math.max(hold, buy + sell);

    }
}