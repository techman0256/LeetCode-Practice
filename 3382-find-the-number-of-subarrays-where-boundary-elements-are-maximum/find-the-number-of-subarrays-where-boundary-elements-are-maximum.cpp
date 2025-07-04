class Solution {
public:
    vector<int> findNGE(vector<int> &nums) {
        int n = nums.size();
        vector<int> nge(n, n);

        stack<int> stk;
        for (int i=n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                stk.pop();
            } 
            if (!stk.empty()) nge[i] = stk.top();
            
            stk.push(i);
        }

        return nge;
    }
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long answer = 0;
        vector<int> nge = findNGE(nums);

        map<int, vector<int>> next_occ;
        for (int i=0; i < n; i++) {
            next_occ[nums[i]].push_back(i);
        }

        for (int i=0; i < n; i++) {
            int curr = upper_bound(next_occ[nums[i]].begin(), next_occ[nums[i]].end(), i) - next_occ[nums[i]].begin();
            int last = upper_bound(next_occ[nums[i]].begin(), next_occ[nums[i]].end(), nge[i]) - next_occ[nums[i]].begin();

            answer += (last - curr + 1);

        }

        return answer;
    }
};