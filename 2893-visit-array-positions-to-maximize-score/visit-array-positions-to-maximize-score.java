class Solution {
    public long maxScore(int[] nums, int x) {
        long memo[][] = new long[nums.length][2];
        
        for (int i=0; i < memo.length; i++) {
            Arrays.fill(memo[i], -1);
        }
        return max(0, nums[0] % 2, nums, (long)x, memo);
    }
    
    static long max(int idx, int par, int nums[], long x, long memo[][]) {
        if (idx == nums.length) return 0;
        
        if (memo[idx][par] != -1) return memo[idx][par];
        
        long take = Integer.MIN_VALUE;

        if (nums[idx] % 2 == par) {
            take = nums[idx] + max(idx + 1, par, nums, x, memo); 
        } 
        else {
            take = nums[idx] - x + max(idx + 1, nums[idx] % 2, nums, x, memo);
        }
        long notTake = max(idx + 1, par, nums, x, memo);
        
        memo[idx][par] = Math.max(take, notTake);
        
        return memo[idx][par];
    }
}