class Solution {
    public int lengthOfLongestSubstring(String s) {
        int lswrc = 0;

        HashMap<Character, Integer> hm = new HashMap<>();
        int left = 0, right = 0;

        while (right < s.length() && left <= right) {
            if (hm.containsKey(s.charAt(right))) {
                lswrc = Math.max(lswrc, right - left);
                int last = hm.get(s.charAt(right));
                hm.replace(s.charAt(right), right);
                left = Math.max(last + 1, left);
                right++;
            } else {
                hm.put(s.charAt(right), right);
                // lswrc = Math.max(lswrc, right - left + 1);
                right++;
            }
        }
        if (right == s.length()) {
            lswrc = Math.max(lswrc, right - left);
        }
        
       
        return lswrc;
    }
}