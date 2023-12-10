class Solution {
    public void moveZeroes(int[] nums) {
        int zero = -1;

        for (int i=0; i < nums.length; i++) {
            if (zero == -1 && nums[i] == 0) {
                zero = i;
            }
            else if (zero != -1 && nums[i] != 0) {
                nums[zero] = nums[zero] + nums[i];
                nums[i] = 0;
                zero++;
            }
        }
    }
}