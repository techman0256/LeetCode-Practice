class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        int dp[][] = new int[n][m];
        for (int i=0; i < n; i++) {
            Arrays.fill(dp[i], - 1);
        }
        int ans = Integer.MIN_VALUE;

        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                int cost = LIP(i, j, matrix, dp);
                ans = Math.max(cost, ans);
            }
        }

        return ans;
    }

    static int LIP(int x, int y, int matrix[][], int memo[][]) {
        int xdirection[] = new int[] {x - 1, x, x + 1, x};
        int ydirection[] = new int[] {y, y - 1, y, y + 1};

        if (memo[x][y] != -1){
            // System.out.println("hi");
            return memo[x][y];
        }

        int max = 0;
        for (int i=0; i < 4; i++) {
            int p = xdirection[i];
            int q = ydirection[i];

            
            if (p >= 0 && q >= 0 && p < matrix.length && q < matrix[0].length && matrix[p][q] > matrix[x][y]) {
               int cost = LIP(p, q, matrix, memo);
               max = Math.max(cost, max);
            }

        }
        memo[x][y] = max + 1;
        return max + 1;
    }
}