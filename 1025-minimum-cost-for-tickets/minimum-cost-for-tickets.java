class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int n = days.length;

        int dp[] = new int[n];
        Arrays.fill(dp, -1);

        return bookTicks(0, days, costs, dp);
    }
    static int bookTicks(int idx, int days[], int costs[], int dp[]) {
        if (idx >= days.length) return 0;
        if ( dp[idx] != -1 ) {
            return dp[idx];
        }

        int day1 = 0, day2 = 0, day7 = 0;

        int p=idx, q=idx, r=idx;
        while (p < days.length && days[p] < days[idx] + 1) p++;
        while (q < days.length && days[q] < days[idx] + 7) q++;
        while (r < days.length && days[r] < days[idx] + 30) r++;
        
        day1 = costs[0] + bookTicks(p, days, costs, dp);
        day2 = costs[1] + bookTicks(q, days, costs, dp);
        day7 = costs[2] + bookTicks(r, days, costs, dp);


        return dp[idx] = Math.min(Math.min(day1, day2), day7);
        
    }
}