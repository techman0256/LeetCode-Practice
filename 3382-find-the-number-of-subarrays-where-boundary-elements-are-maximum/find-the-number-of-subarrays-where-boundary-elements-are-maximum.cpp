class Solution {
public:
    vector<int> next_greater(vector<int> &nums) {
        vector<int> nge( nums.size(), nums.size());
        stack<int> stk;
        for (int i=nums.size() - 1; i >= 0; i--) {
            while ( !stk.empty() && nums[stk.top()] <= nums[i]) {
                stk.pop();
            }

            if ( !stk.empty() ) {
                nge[i] = stk.top();
            } 

            stk.push(i);

        }

        return nge;
    }
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        map<int, vector<int>> occ;
        for (int i=0; i < n; i++) {
            occ[nums[i]].push_back(i);
        }

        for ( auto m : occ ) {
            for ( auto s : m.second) {
                cout << s << " ";
            }
            cout << endl;
        }

        long long cnt = 0;
        vector<int> nge = next_greater(nums);
        // for (int i=0; i < n; i++) {
        //     cout << nge[i] << " ";
        // }
        // cout << endl;
        // auto it = upper_bound(occ[3].begin(), occ[3].end(), 12);
        // int diff = it - occ[3].begin() - 1;
        // cout << diff << endl;
        for (int i=0; i < n; i++) {
            int ng = nge[i];
            int curr = upper_bound(occ[nums[i]].begin(), occ[nums[i]].end(), i) - occ[nums[i]].begin() - 1;
            int last = upper_bound(occ[nums[i]].begin(), occ[nums[i]].end(), ng) - occ[nums[i]].begin() - 1;
            cnt += last - curr + 1;
            // cout << last - curr << endl;
        }    


        return cnt;

    }
};