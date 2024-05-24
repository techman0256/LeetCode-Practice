class Solution {
    public int jump(int[] nums) {
        int n = nums.length;

        int dp[] = new int[n];
        // Arrays.fill()

        for (int i = n - 2; i >=0; i--){
            int minJump = Integer.MAX_VALUE - 1;
            for (int j=i + 1; j < n && j <= i + nums[i]; j++) {
                minJump = Math.min(minJump, dp[j]);
                if (i == n - 2 && j == i + 1) {
                    System.out.println(minJump + " " + i + " " + j);
                }
                
            }

            dp[i] = 1 + minJump;
            System.out.println(dp[i] + " i " + i);
        }
    	
        System.out.println(Arrays.toString(dp));

        return dp[0];
    }
}