class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        int dp[] = new int[n];
        Arrays.fill(dp, -1);

        return breakWord(0, s, wordDict, dp);
    }
    static boolean breakWord(int idx, String s, List<String> wordDict, int dp[]) {
        if (idx >= s.length()) return true;

        if (dp[idx] != -1) {
            if (dp[idx] == 0) return false;
            else return true;
        }

        boolean ans = false;
        for (int k=idx + 1; k <= s.length(); k++) {
            boolean cut = false;
            if ( wordDict.contains(s.substring(idx, k)) ) {
                cut = breakWord(k, s, wordDict, dp);
            }

            ans = ans || cut;
        }

        if (ans == true) dp[idx] = 1;
        else dp[idx] = 0;
        return ans;
    }
}