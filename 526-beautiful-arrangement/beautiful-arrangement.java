class Solution {
    public int countArrangement(int n) {
        int map[] = new int[n + 1];

        return countPermutation(1, n, map);
    }
    static int countPermutation(int idx, int n, int map[]) {
        if (idx == n + 1) {
            return 1;
        }

        int count = 0;
        for (int i=1; i <= n; i++) {
            if ( map[i] == 0 && (i % idx  == 0 || idx % i == 0) ) {
                map[i] = 1;
                count += countPermutation(idx + 1, n, map);
                map[i] = 0;
            }
        }

        return count;
    }
}