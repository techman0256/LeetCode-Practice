class Solution {
    public int longestStrChain(String[] words) {
        int n = words.length;

        // sort the string array according to their length
        Comparator<String> comp = (str1, str2) -> str1.length() - str2.length();

        ArrayList<String> list = new ArrayList<String>();
        Collections.addAll(list, words);
        Collections.sort(list, comp);
        // System.out.println(list.toString());


        int dp[] = new int[n];
        Arrays.fill(dp, 1);
        for (int i=0; i < n; i++) {
            for (int j=0; j < i; j++) {
                if (compare(list.get(j), list.get(i)) == true) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
        
        int max = dp[0];
        for (int i=1; i < n; i++) {
            max = Math.max(dp[i], max);
        }
        

        return max;
    }
    boolean compare(String parent, String child) {
        if (parent.length() + 1 == child.length()) {
            int i = 0;
            int glitch = 0;
            while (i < parent.length()) {
                if (parent.charAt(i) != child.charAt(i + glitch)) {
                    glitch++;
                } else {
                    i++;
                }

                if (glitch > 1) {
                    return false;
                }
            }
        } else {
            return false;
        }
        

        return true;
    }
}