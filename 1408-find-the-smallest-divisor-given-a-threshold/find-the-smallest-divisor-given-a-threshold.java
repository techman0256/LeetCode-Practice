import java.util.*;

class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int max = nums[0];

        for (int i=0; i < nums.length; i++) {
            max = Math.max(nums[i], max);
        }

        int ans = Integer.MAX_VALUE;
        int min = 1;

        while (min <= max) {
            int avg = (min + max) / 2;

            int sum = 0;
            for (int i=0; i < nums.length; i++) {
                sum += Math.ceil((double)(nums[i]) / (double)(avg));
            }

            if (sum <= threshold) {
                ans = avg;
                max = avg - 1;
            }
            else {
                min = avg + 1;
            }


        }

        return ans;
    }
}