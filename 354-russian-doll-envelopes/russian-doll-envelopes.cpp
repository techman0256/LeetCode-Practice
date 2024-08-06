class Solution {
public:
    static bool compare(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        } 
    
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), compare);
        for ( auto env : envelopes ) {
            cout << env[0] << " " << env[1] << endl;
        }

        vector<int > ans;
        ans.push_back(envelopes[0][1]);
        for (int i=1; i < n; i++) {
            int height = envelopes[i][1];
            if (ans.back() < height) {
                ans.push_back(height);
            } else {
                int idx = lower_bound(ans.begin(), ans.end(), height) - ans.begin();
                ans[idx] = height;

            }
        }

        // int ans = INT_MIN;
        // for (int i=0; i < n; i++) {
        //     ans = max(ans, dp[i]);
        // }


        return ans.size();
    }
};