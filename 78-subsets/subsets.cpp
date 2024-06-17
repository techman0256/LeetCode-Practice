class Solution {
public:
    static void rec(int idx, vector<int> subset, vector<int> nums, vector<vector<int>>& ans) {
        if ( idx == nums.size() ) {
            ans.push_back(subset);
            return;
        }

        rec(idx + 1, subset, nums, ans);
        subset.push_back(nums[idx]);
        rec(idx + 1, subset, nums, ans);

        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        rec(0, subset, nums, ans);

        return ans;
    }
};