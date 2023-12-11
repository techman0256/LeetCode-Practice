class Solution {
    public void sortColors(int[] nums) {
        int zeros = 0;
        int twos = nums.length - 1;
        int iter = 0;

        while (iter <= twos) {
            if (nums[iter] == 0) {
                int temp = nums[zeros];
                nums[zeros] = nums[iter];
                nums[iter] = temp;
               
                zeros++;
                iter++;
            }
            else if (nums[iter] == 1) {
                iter++;
            }
            else if (nums[iter] == 2) {
                int temp = nums[iter];
                nums[iter] = nums[twos];
                nums[twos] = temp;
               
                twos--;
            }
        }
    }
}