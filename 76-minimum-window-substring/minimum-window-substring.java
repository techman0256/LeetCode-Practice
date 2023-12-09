class Solution {
    public String minWindow(String s, String t) {
        if (s.length() < t.length()) {
            return "";
        }

        String ans = "";

        HashMap<Character, Integer> hm = new HashMap<>();
        for (int i=0; i < t.length(); i++) {
            if (hm.containsKey(t.charAt(i))) {
                hm.put(t.charAt(i), hm.get(t.charAt(i)) + 1);
            } else {
                hm.put(t.charAt(i), 1);
            }
        }

        int map_len = hm.size();
        int left = 0, right = 0;
        while (right < s.length() && left <= right) {
            if (hm.containsKey(s.charAt(right))) {
                hm.replace(s.charAt(right), hm.get(s.charAt(right)) - 1);
                if (hm.get(s.charAt(right)) == 0) {
                    map_len -= 1;
                }
            }

            while (map_len == 0) {
                String win = s.substring(left, right + 1);
                // System.out.println(win);
                if (ans == "" || win.length() < ans.length()) {
                    ans = win;
                }

                if (hm.containsKey(s.charAt(left))) {
                    hm.replace(s.charAt(left), hm.get(s.charAt(left)) + 1);
                    if (hm.get(s.charAt(left)) > 0) {
                        map_len += 1;
                        // break;
                    }
                }
                left++;
            }
            right++;
        }       



        return ans;
    }
}