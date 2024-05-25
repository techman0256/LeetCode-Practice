class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        int n = s.length();

        int dp[] = new int[n];
        Arrays.fill(dp, -1);
        List<String> ans = new ArrayList<String>();

        return breakWord(0, s, "", wordDict, ans);
    }
    static List<String> breakWord(int idx, String s, String tillNow, List<String> wordDict, List<String> ans) {
        if (idx == s.length()) {
            ans.add(tillNow);
            return ans;
        }
        
        for (int k=idx + 1; k <= s.length(); k++) {
            if ( wordDict.contains(s.substring(idx, k)) ) {
                String passOn = "";
                if (tillNow.equals("")) {
                    passOn = s.substring(idx, k);
                } else {
                    passOn = tillNow + " " + s.substring(idx, k);
                }
                
                
                ans = breakWord(k, s, passOn, wordDict, ans);
            }
            
        }

        return ans;
    }
}