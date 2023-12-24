class Solution {
    public int missingNumber(int[] nums) {
        int sum = ((nums.length + 1) * (nums.length)) / 2;
        int i=0;
        int prefixSum = 0;
        for (i=0; i < nums.length; i++) {
            prefixSum += nums[i];
        }
        return sum - prefixSum;
    }
}