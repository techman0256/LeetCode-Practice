class Solution {
public:
    long long opt(int idx, vector<vector<int>> &rides, vector<int> &start, vector<long long> & dp) {
        if (idx >= start.size()) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int nxt = lower_bound(start.begin(), start.end(), rides[idx][1]) - start.begin();
        long long take = (rides[idx][1] - rides[idx][0] + rides[idx][2]) + opt(nxt, rides, start, dp);
        long long notTake = opt(idx + 1, rides, start, dp);

        return dp[idx] = max(take, notTake);


    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int k = rides.size();
        vector<int> pos;
        vector<long long> dp(k, -1);

        sort(rides.begin(), rides.end());

        for (auto r : rides) {
            pos.push_back(r[0]);
        }

        return opt(0, rides, pos, dp);

    }
};