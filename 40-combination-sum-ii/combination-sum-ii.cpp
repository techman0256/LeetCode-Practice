class Solution {
public:
    static void comb(int idx, vector<int> subset, int target, vector<int> &candidates, set<vector<int>> &set) {
        if (target == 0) {
            cout << endl;
            set.insert(subset);
            return;
        }

        if (idx == candidates.size() || candidates[idx] > target) {
            return;
        }


        // comb(idx + 1, subset, target, candidates, set);
        if (candidates[idx] <= target) {
            subset.push_back(candidates[idx]);
            comb(idx + 1, subset, target - candidates[idx], candidates, set);
            subset.pop_back();
        }
        int j=idx;
        while (j < candidates.size() && candidates[j] == candidates[idx]) {
            j++;
        }
        comb(j, subset, target, candidates, set);

        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        vector<vector<int>> ans;
        set<vector<int>> ss;
        int sum = 0;

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