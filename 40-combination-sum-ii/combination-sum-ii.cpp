class Solution {
public:
    static void comb(int idx, vector<int> subset, int target, vector<int> &candidates, set<vector<int>> &set) {
        if (target == 0) {
            set.insert(subset);
            return;
        }

        if (idx == candidates.size() || candidates[idx] > target) {
            return;
        }


        for (int i=idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            subset.push_back(candidates[i]);
            comb(i + 1, subset, target - candidates[i], candidates, set);
            subset.pop_back();
        }

        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        vector<vector<int>> ans;
        set<vector<int>> ss;
        int sum = 0;
        cout << candidates.size();
        for (int i=0; i < candidates.size(); i++) {
            sum += candidates[i];
        }

        if (sum < target) {
            return ans;
        }
        

        sort(candidates.begin(), candidates.end());

        comb(0, subset, target, candidates, ss);

        for (auto i : ss) {
            ans.push_back(i);
        }

        return ans;

    }
};