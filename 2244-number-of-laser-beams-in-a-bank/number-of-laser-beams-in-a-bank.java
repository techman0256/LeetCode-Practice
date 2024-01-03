class Solution {
    public int numberOfBeams(String[] bank) {
        int m = bank.length;
        int n = bank[0].length();

        int lasers = 0;
        int i = 0, j =  i + 1;
        while (j < m) {
            int row1 = 0;
            int row2 = 0;
            for (int k = 0; k < n; k++) {
                if (bank[i].charAt(k) == '1') {
                    row1++;
                }
                if (bank[j].charAt(k) == '1') {
                    row2++;
                }
            }
            lasers += row1 * row2;
            if (row2 != 0) i = j;
            j++;
        }
        
        return lasers;
    }
}