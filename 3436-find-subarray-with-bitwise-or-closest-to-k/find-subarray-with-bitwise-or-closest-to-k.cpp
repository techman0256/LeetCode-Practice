class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> feasible;
        int ans = INT_MAX;

        for (int i=n - 1; i >= 0; i--) {
            set<int> new_feasible;
            for (int num : feasible) {
                new_feasible.insert( (int)(num | nums[i]) );
            }

            new_feasible.insert(nums[i]);

            for (int a : new_feasible) {
                // if ( abs(or - k) )
                ans = min(ans, abs(a - k));
            }
            feasible = new_feasible;
        }

        return ans;

    }
};