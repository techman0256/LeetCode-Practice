class Solution {
    public int longestOnes(int[] nums, int k) {
        int ans = 0;
        // HashSet<Integer> set = new HashSet<Integer>();
        PriorityQueue<Integer> set = new PriorityQueue<Integer>((a, b) -> a - b);

        int left = 0, right = 0;
        
        while (right < nums.length) {
            if (nums[right] == 0 && set.size() < k) {
                set.add(right);
                ans = Math.max(ans, right - left + 1);
                right++;
            }
            else if (nums[right] == 0 && set.size() >= k) {
                set.add(right);
                int leftmost0 = set.poll();
                left = Math.max(left, leftmost0 + 1);

                ans = Math.max(ans, right - left + 1);
                // System.out.println(ans);
                right++;
            }
            else {
                ans = Math.max(ans, right - left + 1);
                right++;
            }
        }

        return ans;

    }
}