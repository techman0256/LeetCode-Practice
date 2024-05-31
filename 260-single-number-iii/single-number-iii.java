class Solution {
    public int[] singleNumber(int[] nums) {
        
        long xor = 0;
        for (int i=0; i < nums.length; i++) {
            xor = xor ^ nums[i];
        }

        long rightmost = (xor & xor - 1) ^ xor;
        long b1 = 0;
        long b2 = 0;

        for (int i=0; i < nums.length; i++) {
            // System.out.println(nums[i] & rightmost);
            if ((nums[i] & rightmost) != 0) {
                b1 = b1 ^ nums[i];
            } else {
                b2 = b2 ^ nums[i];
            }

        }

        return new int[]{(int)b1, (int)b2};
    }
}