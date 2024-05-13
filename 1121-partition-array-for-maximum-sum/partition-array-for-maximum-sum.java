class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int dp[] = new int[n + 1];

        for (int i=n - 1; i >= 0; i--) {
            int max = Integer.MIN_VALUE;
            int maxi = Integer.MIN_VALUE;    

            for (int j=i; j - i + 1 <= k && j < arr.length; j++) {
                max = Math.max(max, arr[j]);
                int cut =  (max * (j - i + 1)) + dp[j + 1];

                maxi = Math.max(maxi, cut);
            } 
            dp[i] = maxi;
        }

       return dp[0];
    //    return partition(0, arr.length, arr, k); 
    }
    static int partition(int i, int j, int arr[], int atMost) {
        if (i == j) return 0;


        int max = Integer.MIN_VALUE;
        int maxi = Integer.MIN_VALUE;
        for (int k=i; k - i + 1 <= atMost && k < arr.length; k++) {
            max = Math.max(max, arr[k]);
            int cut = (max * (k - i + 1)) + partition(k + 1, j, arr, atMost);
           
            maxi = Math.max(maxi, cut);
        }
        
        // System.out.println(maxi);
        return maxi;
    }
}