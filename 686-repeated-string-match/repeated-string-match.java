class Solution {
    public int repeatedStringMatch(String a, String b) {
        String matcher = "";
        int i=0;
        
        while (matcher.length() < b.length()) {
            i++;
            matcher += a;
        }
        if (isSubstring(b, matcher)) return i;
        i++;
        matcher += a;
        if (isSubstring(b, matcher)) return i;
        else return -1;

    }
    static boolean isSubstring(String a, String b) {
        final int PRIME = 71;
        int count = 0;
        int n = b.length();
        int m = a.length();

        if (m > n) {
            return false;
        }

        long pattern_hash = 0;
        long win_hash = 0;

        // intitialize hash
        for (int i=0; i < m; i++) {
            pattern_hash += a.charAt(i) * Math.pow(PRIME, i);
            win_hash += b.charAt(i) * Math.pow(PRIME, i);
        }

        // sliding window
        int i=0;
        for (i=0; i < n - m; i++) {
            if (pattern_hash == win_hash && a.equals(b.substring(i, i + m))) {
                return true;
            }
            win_hash = ((win_hash - b.charAt(i)) / PRIME);
            win_hash += (b.charAt(i + m) * Math.pow(PRIME, m - 1));

        }
        if (pattern_hash == win_hash && a.equals(b.substring(i, i + m))) {
            return true;
        }


        return false;
    }
}