class Solution {
    public int countSquares(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        int dp[][] = new int[n][m];
        dp = matrix;
        for (int i=0; i < n; i++) {
            // for (int j=0; j < m; j++) {
            //     ans += dp[i][j];
            // }
            System.out.println(Arrays.toString(dp[i]));
        }

        for (int i=1; i < n; i++) {
            for (int j=1; j < m; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = 1 + Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        int ans = 0;
        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                ans += dp[i][j];
            }
            System.out.println(Arrays.toString(dp[i]));
        }

        return ans;
    }
}