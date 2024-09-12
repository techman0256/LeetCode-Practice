class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;

        int score = 0;
        int ans = 0;
        HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
        int start = 0, end = 0;
        while (end < n) {
            if (hm.getOrDefault(nums[end], 0) == 1) {
                ans = Math.max(ans, score);
                hm.put(nums[start], 0);
                score -= nums[start];
                start++;
            } else {
                hm.put(nums[end], hm.getOrDefault(nums[end], 0) + 1);
                score += nums[end];
                end++;

            }
        }
                ans = Math.max(ans, score);
        // if (hm.getOrDefault(nums[end], 0) == 1) {
        //         hm.put(nums[start], 0);
        //         score -= nums[start];
        //         start++;
        //     }

        return ans;
    }
}