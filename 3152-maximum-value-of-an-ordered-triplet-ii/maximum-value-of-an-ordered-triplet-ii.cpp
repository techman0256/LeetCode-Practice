class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix_max(n), suffix_max(n);
        
        // Build prefix_max (max from start to i)
        prefix_max[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_max[i] = max((long long)nums[i], prefix_max[i - 1]);
        }

        // Build suffix_max (max from i to end)
        suffix_max[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix_max[i] = max((long long)nums[i], suffix_max[i + 1]);
        }

        long long answer = 0;

        for (int j=1; j < n - 1; j++) {
            long long value = (prefix_max[j - 1] - nums[j]) * suffix_max[j + 1];
            answer = max(answer, value);
        }


        return answer;
    }
};