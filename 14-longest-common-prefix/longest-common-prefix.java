class Solution {
    public String longestCommonPrefix(String[] strs) {
        String prefix = strs[0];
        for (int i=1; i < strs.length; i++) {
            String str = strs[i];
            int j = 0;
            for (j = 0; j < Math.min(str.length(), prefix.length()); j++) {
                if (str.charAt(j) != prefix.charAt(j)) {
                    break;
                }
            }
            prefix = prefix.substring(0, j);
        }
        return prefix;
    }
}