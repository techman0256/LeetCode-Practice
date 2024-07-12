class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i=0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        long long ans = LONG_MIN;
        
        map<int, int> mpp;
        for (int i=0; i < n; i++) {
            int need1 = nums[i] - k;
            int need2 = nums[i] + k;
            if (mpp.find(need1) != mpp.end()) {
                ans = max(ans, prefix[i + 1] - prefix[mpp[need1]]);
            }

            if (mpp.find(need2) != mpp.end()) {
                ans = max(ans, prefix[i + 1] - prefix[mpp[need2]]);
            }
            
            if ( mpp.find(nums[i]) == mpp.end() || (mpp.find(nums[i]) != mpp.end() && prefix[mpp[nums[i]]] > prefix[i])) {
                mpp[nums[i]] = i;
            }
            // mpp[nums[i] + k]push_back(i);
            // mpp[nums[i] - k].push_back(i);
        }
        if (ans == LONG_MIN) return 0;

        return ans;       

    }
};