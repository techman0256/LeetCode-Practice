class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        int n = satisfaction.length;

        int dp[][] = new int[n + 1][n + 1];
        for (int i=0; i <= n; i++) {
            Arrays.fill(dp[i], -10000000);
            // for (int j=0; j <= n; j++) {
        //         Arrays.fill(dp[i][j], -10000000);
        //     }
        }

        Arrays.sort(satisfaction);
        return makeDishes(satisfaction, 1, 0, n - 1, dp);
    }
    static int makeDishes(int[] satisfaction, int time, int i, int j, int dp[][]) {
        if (i >= satisfaction.length) return 0;
        if (time > satisfaction.length) return 0;

        if (dp[i][time] != -10000000) {
            // System.out.println("hello" + " " + i + " " + j + " " + time);
            return dp[i][time];
        }

    
       

        return dp[i][time] = Math.max(satisfaction[i] * time + makeDishes(satisfaction, time + 1, i + 1, j, dp), makeDishes(satisfaction, time, i + 1, j, dp));
    }
}