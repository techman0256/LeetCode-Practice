class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
        int max_freq = 0;

        //creating a hashmap
        for (int i=0; i < nums.length; i++) {
            if (hm.containsKey(nums[i])) {
                hm.put(nums[i], hm.get(nums[i]) + 1);
            } else {
                hm.put(nums[i], 1);
            }
            
            // if (hm.get(nums[i]) > max_freq) {

            // }
        }
        max_freq = Collections.max(hm.values());

        List<List<Integer>> ans = new ArrayList<>();
        for (int i=0; i < max_freq; i++) {
            ans.add(new ArrayList<Integer>());
        }

        for (Map.Entry<Integer, Integer> entry : hm.entrySet()) { 
            // System.out.println("Key = " + entry.getKey() + ", Value = " + entry.getValue()); 
            for (int i=0; i < entry.getValue(); i++) {
                ans.get(i).add(entry.getKey());
            }

        }
        return ans;
    }
}