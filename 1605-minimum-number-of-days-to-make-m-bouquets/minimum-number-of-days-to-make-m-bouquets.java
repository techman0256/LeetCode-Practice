class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        if (bloomDay.length < m * k) return -1;
        
        // return makeBouquets(3, bloomDay, m, k);
        int min = Integer.MAX_VALUE;
        int max = 0;
        int ans = -1;
        for (int i=0; i < bloomDay.length; i++) {
            min = Math.min(min, bloomDay[i]);
            max = Math.max(max, bloomDay[i]);
        }

        while (min <= max) {
            int mid = (min + max) / 2;
            int days = makeBouquets(mid, bloomDay, m, k);
            if (days == -1) {
                min = mid + 1;
            }
            else {
                ans = mid;
                max = mid - 1;
            }
        }

        return ans;

    }

    static int makeBouquets(int day, int[] bloomDay, int m, int k) {
        int makeM = 0;
        int makeK = 0;

        for (int i=0; i < bloomDay.length; i++) {
            if (makeK == k){
                makeM ++;
                makeK = 0;
            }
            
            if (bloomDay[i] > day) {
                makeK = 0;
            } else {
                makeK ++;
            }
        }
        if (makeK == k){
                makeM ++;
                makeK = 0;
        }

        // System.out.println(makeM);
        if (makeM >= m) return day;
        else return -1;
    }
}