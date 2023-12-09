class Solution {
    public int removeDuplicates(int[] nums) {
        int sorted = 0;
        int element = nums[0];

        for (int i=0; i < nums.length; i++) {
            if (nums[i] != element) {
                nums[sorted] = element;
                sorted ++;
                element = nums[i];
            }
        }
        nums[sorted] = element;
        
        return ++sorted;
    }
}