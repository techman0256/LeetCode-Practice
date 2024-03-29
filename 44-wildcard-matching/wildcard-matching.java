class Solution {
    public boolean isMatch(String s, String p) {
        int n = s.length();
        int m = p.length();

        boolean dp[][] = new boolean[n + 1][m + 1];
        int t=0;
        while (t < m && p.charAt(t) == '*') {
            dp[0][t+1] = true;
            t++;
        }
        dp[0][0] = true;
        // for (int i=0; i <= m; i++) {
        //     System.out.println(dp[0][i]);
        // }
        // if (dp[0][1] == true) 

        for (int i=1; i <= n; i++) {
            for (int j=1; j <=m; j++) {
                if (p.charAt(j - 1) == '?' || s.charAt(i - 1) == p.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p.charAt(j - 1) == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 1] || dp[i][j - 1];
                }
            }
        }

        return dp[n][m];
    //    return Match(n - 1, m - 1, s, p); 
    }
    static boolean Match(int i, int j, String s, String p) {
        if (i < 0) {
            while (j >= 0) {
                if (p.charAt(j) != '*') {
                    return false;
                }
                j--;
            }
            return true;
        }
        if (j < 0) return false;
        
        boolean ans = false;
        if (p.charAt(j) == '?' || s.charAt(i) == p.charAt(j)) {
            ans = Match(i - 1, j - 1, s, p);
        } else if (p.charAt(j) == '*') {
            ans = Match(i - 1, j, s, p) || Match(i - 1, j - 1, s, p) || Match(i, j - 1, s , p);
        }
        return ans;
    }
}