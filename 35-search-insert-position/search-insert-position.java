class Solution {
    public int searchInsert(int[] nums, int target) {
        int n = nums.length;

        int left = 0, right = n - 1;
        int idx = n;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                idx = Math.min(idx, mid);
                right = mid - 1;
            }
        }

        return idx;


    }
}