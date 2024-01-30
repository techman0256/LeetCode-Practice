class Solution {
    public int strStr(String b, String a) {
        final int PRIME = 71;
        int count = 0;
        int n = b.length();
        int m = a.length();

        if (m > n) {
            return -1;
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
                return i;
            }
            win_hash = ((win_hash - b.charAt(i)) / PRIME);
            win_hash += (b.charAt(i + m) * Math.pow(PRIME, m - 1));

        }
        if (pattern_hash == win_hash && a.equals(b.substring(i, i + m))) {
            return i;
        }


        return -1;
    }
}