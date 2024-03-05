class Solution {
    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int m = amount;

        int dp[][] = new int[n][m + 1];
        // for (int i=0; i < n; i++) {
        //     Arrays.fill(dp[i], Integer.MAX_VALUE);
        // }
        // base case
        dp[0][0] = 0;
        for (int i=0; i < n; i++) {
        }
        for (int i=1; i <= m; i++) {
            if (i % coins[0] == 0) dp[0][i] = i / coins[0];
            else dp[0][i] = Integer.MAX_VALUE - 1;
        }
        
        for (int i=1; i < n; i++) {
            for (int j=0; j <= m; j++) {
                int notPick = dp[i - 1][j];
                int pick = Integer.MAX_VALUE;
                if (coins[i] <= j){
                    // int target = 
                    pick = 1 + dp[i][j - coins[i]];
                    // pick = (j / coins[i]) + dp[i - 1][j % coins[i]];

                } 

                dp[i][j] = Math.min(notPick, pick);
            }
        }
        // for (int i=0; i < n; i++) {
        //     for (int j=0; j <= m; j++) {
        //         System.out.print(dp[i][j] + " ");
        //     }
        //     System.out.println();
        // }

        if (dp[n - 1][m] >= Integer.MAX_VALUE - 1) return -1;
        return dp[n - 1][m];
    }
}