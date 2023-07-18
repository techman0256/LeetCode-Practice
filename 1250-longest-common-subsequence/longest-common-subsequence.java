class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();

        int prev[] = new int[m+1];
        int curr[] = new int[m+1];

        // base case is prev[i] = 0 for 0 < i < m + 1

        for (int i=1; i <= n; i++) {
            for (int j=1; j <=m; j++) {
                int take = Integer.MIN_VALUE;
                if (text1.charAt(i-1) == text2.charAt(j-1)) {
                    take = 1 + prev[j-1];
                }

                int left = curr[j-1];
                int right = prev[j];

                curr[j] = Math.max(take, Math.max(left, right));
            }
            prev = curr;
            curr = new int[m+1];
        }
        return prev[m];
        
    }  
}