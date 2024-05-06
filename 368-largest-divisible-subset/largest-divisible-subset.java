class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;
        Integer[] num = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        
        ArrayList<Integer> data = new ArrayList<Integer>();
        Collections.addAll(data, num);
        Collections.sort(data);

        int dp[] = new int[n];
        int pos[] = new int[n];

        for (int i=0; i < n; i++) {
            dp[i] = 1;
            pos[i] = i;
        }

        for (int i=0; i < n; i++) {
            for (int j=0; j < i; j++) {
                if (data.get(i) % data.get(j) == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pos[i] = j;
                }
            }
        }

        int max = dp[0];
        int idx = 0;

        for (int i=1; i < n; i++) {
            if (max < dp[i]) {
                max = dp[i];
                idx = i;
            }
        }

        ArrayList<Integer> subset = new ArrayList<Integer>();
        while (idx != pos[idx]) {
            subset.add(0, data.get(idx));
            idx = pos[idx];
        }
        subset.add(0, data.get(idx));

        return subset;




        

        // return fx(0, new ArrayList<Integer>(), nums);
    } 
    // static List<Integer> fx(int idx, int last, int[] nums) {
    //     if (idx == nums.length) {
    //         return new ArrayList<Integer>();
    //     }

    //     Int

    //     ArrayList<Integer> take;
    //     if (nums[idx] % nums[last] == 0) {
    //         take = 
    //     }

    //     int flag = 1;
    //     for (Integer j : answer) {
    //         if (!(j % nums[idx] == 0|| nums[idx] % j == 0)) {
    //             flag = 0;
    //         }
    //     }
    //     ArrayList<Integer> take = new ArrayList<Integer>(answer);
    //     if (flag == 1) {
    //         take.add(nums[idx]);
    //         take.addAll(fx(idx + 1, take, nums));
    //     }
    //     ArrayList<Integer> notTake = new ArrayList<Integer>(answer);
    //     notTake.addAll(fx(idx + 1, notTake, nums));

    //     return take.size() > notTake.size() ? take : notTake;

    // }
}