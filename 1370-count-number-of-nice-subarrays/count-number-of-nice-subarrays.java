class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        return atMostKNice(nums, k) - atMostKNice(nums, k - 1);
    }
    static int atMostKNice(int[] nums, int k) {
        if (k < 0) return 0;
        int ans = 0;
        int left = 0, right = 0;
        int odd_in_win = 0;
        while (right < nums.length) {
            if (nums[right] % 2 == 1) {
                odd_in_win += 1;
            }

            while (odd_in_win > k) {
                if (nums[left] % 2 == 1) odd_in_win -= 1;
                // else {
                //     ans += 1;
                // }
                left++;
            }

            ans += right - left + 1;
            right++;
        }
        // System.out.println(ans);
        return ans;
    }
}