class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();

        int dp[][] = new int[n + 1][m + 1];

        // for (int i=0; i < m; i++) {
        //     if (text1.charAt(0) == text2.charAt(i)) {
        //         dp[0][i] = 1;
        //     }
        // }

        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                if (text1.charAt(i) == text2.charAt(j)) {
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                } else {
                    dp[i + 1][j + 1] = Math.max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        return dp[n][m];
    }
}