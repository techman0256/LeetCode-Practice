class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        int n = str1.length();
        int m = str2.length();
        
        int dp[][] = new int[n+1][m+1];
        // for (int i=0; i < n; i++) {
        //     Arrays.fill(dp[i], -1);
        // }

        String ans = "";
        for (int i=1; i <= n; i++) {
            for (int j=1; j <= m; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    // ans += str1.charAt(i - 1);
                } else {
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        //  for (int i=1; i <= n; i++) {
        //     for (int j=1; j <= m; j++) {
        //        System.out.print(dp[i][j] + " ");
        //     }
        //     System.out.println();

        // }

        int p = n, q = m;

        while (p > 0 && q > 0) {
            if (str1.charAt(p - 1) == str2.charAt(q - 1)) {
                // System.out.println(p + " " + q);
                ans = str1.charAt(p - 1) + ans;
                p--;
                q--;
            }
            else if (dp[p][q - 1] > dp[p - 1][q]) {
                ans = str2.charAt(q - 1) + ans;
                q--;
            } else {
                ans = str1.charAt(p - 1) + ans;
                p--;
            }
        }


        // System.out.println(ans);
        while (p > 0) {
            ans = str1.charAt(p - 1) + ans;
            p--;
        } 
        while (q > 0) {
            ans = str2.charAt(q - 1) + ans;
            q--;
        }



        return ans;
    }
}