class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hm = new HashMap<>();

        for (int i=0; i < nums.length; i++) {
            if (hm.containsKey(nums[i])) {
                return new int[]{hm.get(nums[i]), i};
            }

            int need = target - nums[i];
            hm.put(need, i);
        }

        return new int[2];
    }
}