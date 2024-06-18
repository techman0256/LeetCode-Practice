class Solution {
public:
    static void rec(int idx, vector<int> ss, vector<int> &nums, vector<vector<int>> &ans) {
        if (idx == nums.size()) {
            ans.push_back(ss);
            return;
        }

        ss.push_back(nums[idx]);
        rec(idx + 1, ss, nums, ans);
        ss.pop_back();

        int j=idx;
        while (j < nums.size() && nums[j] == nums[idx]) {
            j++;
        }

        rec(j, ss, nums, ans);

        
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ss;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        rec(0, ss, nums, ans);

        return ans;
    }
};