class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums) {
        Stack<Integer> stk = new Stack<Integer>();
        HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();

        int n = nums.length;
        for (int i=n - 1; i >= 0; i--) {
            while (!stk.isEmpty() && stk.peek() < nums[i]) {
                stk.pop();
            }

            if (stk.isEmpty()) {
                hm.put(nums[i], -1);                
            } else {
                hm.put(nums[i], stk.peek());
            }
            stk.push(nums[i]);
        }

        for (int i=0; i < nums1.length; i++) {
            nums1[i] = hm.get(nums1[i]);
        }
        return nums1;
    }
}