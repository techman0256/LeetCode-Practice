class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        int max = nums[0];
        for (int i=0; i < nums.length; i++) {
            if (count == 0) {
                max = nums[i];
            }

            if (nums[i] == max) {
                count++;
            } else {
                count--;
            }
        }

        return max;
        // int verify = 0;
        // for (int i=0; i < nums.length; i++) {
        //     if (nums[i] == max) verify++;
        // }

        // if (verify > nums.length / 2) return max;
        // else return -1;
    }
}