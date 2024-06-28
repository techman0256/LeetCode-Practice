class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int E = roads.size();
        vector<pair<int, int>> imp;
        vector<long long> importance(n, 0);

        vector<vector<int>> adj(n);
        for (int i=0; i < E; i++) {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }

        for (int i=0; i < n; i++) {
            imp.push_back({i, adj[i].size()});
        }

        sort(imp.begin(), imp.end(), compare);
        long long max = n;
        for (auto city : imp) {
            importance[city.first] = max;
            max--;
        }

        long long ans = 0;
        for (int i=0; i < E; i++) {
            ans += importance[roads[i][0]] + importance[roads[i][1]];
        }

        return ans;
    }
};