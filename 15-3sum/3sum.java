class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        HashSet<List<Integer>> ans = new HashSet<>();
        HashSet<Integer> map = new HashSet<>();

        for (int i=0; i < nums.length; i++) {
            for (int j=i+1; j < nums.length; j++) {
                int req = -(nums[i] + nums[j]);

                if (map.contains(req)) {
                    List<Integer> tuple = new ArrayList<Integer>();
                    tuple.add(req);
                    tuple.add(nums[i]);
                    tuple.add(nums[j]);
                    Collections.sort(tuple);
                    ans.add(tuple);
                } else {
                    map.add(nums[j]);
                }
            }
            map.clear();
        }

        return new ArrayList<>(ans);
    }
}