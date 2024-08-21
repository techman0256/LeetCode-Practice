class Solution {
    int prefix[];
    int dp[][][];
    int stoneGame(int idx, int M, int turn, int[] piles) {
        if (idx == piles.length) {
            return 0;
        }

        if (dp[idx][M][turn] != 0) {
            // System.out.println("hello");
            return dp[idx][M][turn];
        }

        int maxi = turn == 0 ? 0 : Integer.MAX_VALUE;
        for (int X=1; (X <= 2 * M) && (idx + X <= piles.length); X++) {
            int stone = 0;
            if (turn == 0) {
                stone += this.prefix[idx + X] - this.prefix[idx];
            }

            if (turn == 0) {
                maxi = Math.max(maxi, stone + stoneGame(idx + X , Math.max(M, X), (turn + 1) % 2, piles));
            } else {
                maxi = Math.min(maxi, stoneGame(idx + X, Math.max(M, X), (turn + 1) % 2, piles));
            }
            // System.out.println(idx + " before " + stone);
            // stone += stoneGame(idx + X , Math.max(M, X), (turn + 1) % 2, piles);
            // System.out.println(idx + " " + stone);
            // maxi = Math.max(stone, maxi);
        }

        return dp[idx][M][turn] = maxi;
    }
    public int stoneGameII(int[] piles) {
        this.prefix = new int[piles.length + 1];
        dp = new int[101][101][2];

    
        for (int i=0; i < piles.length; i++) {
            this.prefix[i + 1] = piles[i] + this.prefix[i];
        }

        int ans = stoneGame(0, 1, 0, piles);

        return ans;
    }
}