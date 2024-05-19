class Solution {
    public int countPrimes(int n) {
        boolean nums[] = new boolean[n + 1]; 
        // for (int i=3; i <= n; i++) {
        //     nums[i] = true;
        // }
        // nums[0] = nums[1] = true;
        
        for (int i=2; i * i <= n; i++) {
            if (nums[i] == false) {
                for (int j= i * i; j <= n; j += i) {
                    nums[j] = true;
                }
            }
        }

        int cnt = 0;
        for (int i=2; i < n; i++) {
            if (nums[i] == false) {
                cnt++;
            }
        }

        return cnt++;
    }
}