class Solution {
    public long subArrayRanges(int[] nums) {
        // int n = nums.length;
        return maxSum(nums) - minSum(nums);

    }
    static long maxSum(int nums[] ) {
        int n = nums.length;
        int lge[] = new int[n];
        int rge[] = new int[n];

        Stack<Integer> stk = new Stack<Integer>();

        for (int i=0; i < n; i++) {
            while (!stk.isEmpty() && nums[stk.peek()] <= nums[i]) {
                stk.pop();
            }
            if (stk.isEmpty()) {
                lge[i] = -1;
            } else {
                lge[i] = stk.peek();
            }
            stk.push(i);
        }

        stk.clear();

        for (int i= n - 1; i >=0; i--) {
            while (!stk.isEmpty() && nums[stk.peek()] < nums[i]) {
                stk.pop();
            }
            if (stk.isEmpty()) {
                rge[i] = n;
            } else {
                rge[i] = stk.peek();
            }
            stk.push(i);
        }
        // System.out.println(Arrays.toString(lge));
        // System.out.println(Arrays.toString(rge));
       
        long sum = 0;
        for (int i=0; i < n; i++) {
            int time = (i - lge[i]) * (rge[i] - i);
            sum += (long)nums[i] * (long)(time);
            
            // System.out.println(sum + ": is " + nums[i] + " tims " + times);
        }

        return sum;
    }
    static long minSum(int nums[]) {
        int n = nums.length;
        int lse[] = new int[n];
        int rse[] = new int[n];
        Stack<Integer> stk = new Stack<Integer>();

        for (int i=0; i < n; i++) {
            while (!stk.isEmpty() && nums[stk.peek()] > nums[i]) {
                stk.pop();
            }

            if (stk.isEmpty()) {
                lse[i] = -1;
            } else {
                lse[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();

        for (int i=n - 1; i >=0; i--) {
             while (!stk.isEmpty() && nums[stk.peek()] >= nums[i]) {
                stk.pop();
            }

            if (stk.isEmpty()) {
                rse[i] = n;
            } else {
                rse[i] = stk.peek();
            }
            stk.push(i);
        }

        // System.out.println(Arrays.toString(lse));
        // System.out.println(Arrays.toString(rse));
        long mod = 1000000007;
        long sum = 0;
        for (int i=0; i < n; i++) {
            int time = (i - lse[i]) * (rse[i] - i);
            sum += (long)nums[i] * (long)(time);

            // System.out.println(sum + ": is " + nums[i] + " tims " + times);
        }
        
        return sum;
    }
}