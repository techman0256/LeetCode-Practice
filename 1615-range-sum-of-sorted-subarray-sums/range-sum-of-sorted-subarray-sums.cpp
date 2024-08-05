class Solution {
    int MOD = 1e9 + 7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // int n = nums.size();

        vector<int> subSum;
        vector<int> prefix(n + 1, 0);
        // prefix[0] = nums[0];
        for (int i=1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        for (int i=0; i < n; i++) {
            for (int j=i + 1; j <= n; j++) {
                subSum.push_back(prefix[j] - prefix[i]);
            }
        }

        sort(subSum.begin(), subSum.end());
        // for ( auto ele : subSum) {
        //     cout << ele << endl;
        // }

        int ans = 0;
        for (int i=left - 1; i < right; i++) {
            ans = ( (ans % MOD) + (subSum[i] % MOD) ) %MOD  ;
        }

        return ans;

    }
};