class Solution {
    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();

        // if (word1.length() == 0) return word2.length();

        int dp[][] = new int[n + 1][m + 1];
        for (int i=0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int i=0; i <= m; i++) {
            dp[0][i] = i;
        }

        for (int i=1; i <= n; i++) {
            for (int j=1; j <= m; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + Math.min(dp[i][j - 1], Math.min(dp[i- 1][j], dp[i - 1][j - 1]));
                }
            }
        }
        // return fx(n - 1, m - 1, word1, word2);
        return dp[n][m];
    }
     static int fx(int i, int j, String a, String b) {
        if (i < 0) return j + 1;
        if (j < 0) {
            return i + 1;
        }
        
        int ans = 0;
        if (a.charAt(i) == b.charAt(j)) {
            ans = fx(i - 1, j - 1, a, b);
        } else {
            int replace = 1 + fx(i - 1, j - 1, a, b);
            int delete = 1 + fx(i - 1, j, a, b);
            int insert  = 1 + fx(i, j - 1, a, b);
            ans = Math.min(insert, Math.min(replace, delete));
        }

        return ans;
    }
   
}