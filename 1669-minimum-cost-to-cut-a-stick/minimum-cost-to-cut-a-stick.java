class Solution {
    public int minCost(int n, int[] cuts) {
        Arrays.sort(cuts);

        int pos[] = new int[cuts.length + 2];
        int N = pos.length;
        for (int i=0; i < cuts.length; i++) {
            pos[i + 1] = cuts[i];
        }
        pos[N  - 1] = n;

        System.out.println(Arrays.toString(pos));

        int dp[][] = new int[N][N];
        // for (int i=0; i < N; i++) {
        //     for (int j=0; j < N; j++) {
        //         System.out.print(dp[i][j] + " ");
        //     }
        //     System.out.println();
        // }

        for (int i=N - 2; i >= 1; i--) {
            for (int j=i; j < N - 1; j++) {
                int min = Integer.MAX_VALUE;

                for (int k=i; k <= j; k++) {
                    int cut = dp[i][k - 1] + dp[k + 1][j] + pos[j + 1] - pos[i - 1];
                    // System.out.println(i + " " + j);
                    // System.out.println(dp[i][k] + " " + dp[k][j]);
                    // System.out.println(cut + " " + dp[i][k] + " " + dp[k][j] + " " + pos[j] + " " + pos[i]);
                    min = Math.min(cut, min);
                }

                dp[i][j] = min;
            }
        }

        // for (int i=0; i < N; i++) {
        //     for (int j=0; j < N; j++) {
        //         System.out.print(dp[i][j] + " ");
        //     }
        //     System.out.println();
        // }

        return dp[1][N - 2];
        
        // return fx(1, N - 2, pos, dp);
    }
    static int fx(int i, int j, int nums[], int dp[][]) {
        // base case is pretty important guys 
        if (i > j) return 0;


        int min = Integer.MAX_VALUE;

        for (int k=i; k <= j; k++) {
            int cut = fx(i, k - 1, nums, dp) + fx(k + 1, j, nums, dp) + nums[j + 1] - nums[i - 1];

            min = Math.min(min, cut);
        }

        return min;
    }
}