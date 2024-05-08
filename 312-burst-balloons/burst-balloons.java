class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int array[] = new int[n + 2];

        for (int i=0; i < n; i++) {
            array[i + 1] = nums[i];
        }
        array[0] = 1;
        array[n + 1] = 1;

        System.out.println(Arrays.toString(array));

        int N = array.length;
        int dp[][] = new int[N][N];

        for (int i=N - 2; i >= 1; i--) {
            for (int j=i; j < N - 1; j++) {
                int min = Integer.MIN_VALUE;

                for (int k=i; k <= j; k++) {
                    int burst = dp[i][k - 1] + dp[k + 1][j] + (array[i - 1] * array[k] * array[j + 1]);

                    min = Math.max(min, burst);
                }
                dp[i][j] = min;
            }

        }

        return dp[1][N - 2];
        // return fx(1, N - 2, array);
    }
    static int fx(int i, int j, int array[]) {
        // base case
        if (i > j) return 0;

        int min = Integer.MIN_VALUE;
        for (int k=i; k <= j; k++) {
            int burst = (array[i - 1] * array[k] * array[j + 1]) + fx (i , k - 1, array) + fx(k + 1, j, array);

            min = Math.max(min, burst);
        }

        return min;
    }
}