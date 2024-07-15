class Solution {
public:
    // int cut(int idx, vector<vector<int>>& wall) {

    // }
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();

        int m = accumulate(wall[0].begin(), wall[0].end(), 0);
        if (m == 1) {
            return n;
        }

        map<int, int> gap;

        // vector<int> curr(n, 0);
        // vector<int> sum(n, 0);

        for (int i=0; i < n; i++) {
            int sum = 0;
            for (int j=0; j < wall[i].size(); j++) {
                sum += wall[i][j];
                gap[sum]++;
            }
        }
        int ans = INT_MAX;

        for ( auto g : gap ) {
            if (g.first != m) {
                ans = min(ans, n -  g.second);
            } 
            cout << g.first << " " << g.second << endl;
        }
        if (ans == INT_MAX) return gap[m];

        return ans;
    }
};