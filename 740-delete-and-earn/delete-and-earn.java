class Solution {
    public int deleteAndEarn(int[] nums) {
        int n = nums.length;
        int dp[] = new int[n + 1];

        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int i=0; i < n; i++) {
            if (hm.containsKey(nums[i])) {
                hm.put(nums[i], hm.get(nums[i]) + 1);
            } else {
                hm.put(nums[i], 1);
            }
        }
        // for (int i=0; i <= n; i++) {
        Arrays.fill(dp, -1);
        // }

        Arrays.sort(nums);
        return maxEarn(0, nums, dp, hm);
    }
    static int maxEarn(int idx, int[] nums, int dp[], HashMap<Integer, Integer> hm) {
        if (idx >= nums.length) return 0;
        int take = 0, notTake = 0;

        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        int adj = hm.getOrDefault(nums[idx] + 1, 0);
        int times = hm.get(nums[idx]);
        
        take = (times * nums[idx]) + maxEarn(idx + adj + times, nums, dp, hm);
        notTake = maxEarn(idx + times,  nums, dp, hm);

        return dp[idx] = Math.max(take, notTake);
    }
}