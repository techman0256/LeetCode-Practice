class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {

        return atMostKSubarray(nums, goal) - atMostKSubarray(nums, goal - 1);
    }
    static int atMostKSubarray(int[] nums, int goal) {
        if (goal < 0) return 0;
        
        int ans = 0;
        int sum = 0;
        int left = 0, right = 0;

        while (right < nums.length) {
            sum += nums[right];

            while (sum > goal) {
                sum -= nums[left];
                left++;
            }

            ans += (right - left + 1);
            right++;
        }
        return ans;
    }
}