class Solution {
    public int candy(int[] rating) {
        int n = rating.length;
        if (n == 1) return 1;


        int candy[] = new int[n];
        Arrays.fill(candy, 1);

        if (rating[0] > rating[1]) candy[0] = candy[1] + 1;
        for (int i=1; i < n - 1; i++) {
            // int min_neigh = Math.min(rating[i- 1], rating[i + 1]);
            int min_neigh =0, min_candy = 0;
            if (rating[i - 1] < rating[i] && rating[i + 1] < rating[i]) {
                candy[i] = Math.max(candy[i - 1], candy[i + 1]) + 1;
            } else if (rating[i - 1] < rating[i]) {
                candy[i] = candy[i - 1] + 1;
            } else if (rating[i + 1] < rating[i]) {
                candy[i] = candy[i + 1] + 1;
            }
                     
            System.out.print(candy[i] + " ");
        }
        if (rating[n - 1] > rating[n - 2]) candy[n - 1] = candy[n - 2] + 1;;

        for (int i= n - 2; i >= 0; i--) {
            // int min_neigh = Math.min(rating[i- 1], rating[i + 1]);
            if (rating[i] > rating[i + 1] && candy[i] <= candy[i + 1]) {
                candy[i] = candy[i + 1] + 1;
                // System.out.print(rating[i] + " ");

            } 
        }

        int ans = 0;
        for (int i=0; i < n; i++) {
            ans += candy[i];
        }

        return ans;
    }
}