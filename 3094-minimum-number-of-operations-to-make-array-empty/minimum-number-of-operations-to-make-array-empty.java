class Solution {
    public int minOperations(int[] nums) {
        Arrays.sort(nums);
        int curr = Integer.MIN_VALUE;
        int count = 0;
        int ans = 0;
        for (int i=0; i < nums.length; i++) {
            if (curr != nums[i]) {
                if (count == 1) return -1;
                ans += count / 3;
                if (count % 3 > 0) ans++;
                // System.out.println("count " + count + " " + curr);
                curr = nums[i];
                count = 1;
            } else {
                count++;
            }

        }
        if (count == 1) return -1;
            ans += count / 3;
            if (count % 3 > 0) ans++;
        return ans;     
        // HashMap<Integer, Integer> hm = new HashMap<>();

        // for (int i=0; i < nums.length; i++) {
        //     if (hm.containsKey(nums[i])) {
        //         hm.put(nums[i], hm.get(nums[i]) + 1);
        //     } else {
        //         hm.put(nums[i], 1);
        //     }
        // }

        // for (Map.Entry<Integer, Integer> entry : hm.entrySet()) {
            
        // }
    }
}