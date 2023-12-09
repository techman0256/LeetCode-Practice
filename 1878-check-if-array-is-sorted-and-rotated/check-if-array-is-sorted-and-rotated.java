class Solution {
    public boolean check(int[] nums) {
        boolean ans = false;
        for (int i=0; i < nums.length; i++) {
            if (isSorted(nums, i) == true) {
                // System.out.println(i);
                ans = ans || true;
            }
        }
        return ans;
    }
    static boolean isSorted(int[] nums, int idx) {
        for (int i=0; i < nums.length - 1; i++) {
            if (nums[idx % nums.length] > nums[(idx + 1) % nums.length]) {
                return false;
            }
            idx = (idx + 1) % nums.length;
        }
        return true;
    }
}