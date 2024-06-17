class Solution {
public:
    static void combination(int idx, vector<int> comb, int target, vector<int>& candidates, set<vector<int>> &set) {
        if (target == 0) {
            set.insert(comb);
            return;
        }

        if (idx == candidates.size()) {
            return;
        }

        
        combination(idx + 1, comb, target, candidates, set);
        if (candidates[idx] <= target) {
            comb.push_back(candidates[idx]);
            combination(idx, comb, target - candidates[idx], candidates, set);
            // combination(idx + 1, comb, target - candidates[idx], candidates, set);
        }

        return;
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        set<vector<int>> set;
        vector<vector<int>> ans;

        combination(0, comb, target, candidates, set);

        for (auto i : set) {
            ans.push_back(i);
        }

        return ans;
    }
};