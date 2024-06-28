class Solution {
public:
    static int minHP(int row, int col, vector<vector<int>> &dp, vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        if (row >= n || col >= m) return INT_MAX;
        if (row == n - 1 && col == m - 1) {
            if (dungeon[row][col] > 0) return 1;
            else return 1 - dungeon[row][col];
        }

        if (dp[row][col] != -1) {
            // cout << "HI" << endl;
            return dp[row][col];
        }

        int down = minHP(row, col + 1, dp, dungeon);
        int right = minHP(row + 1, col, dp, dungeon);
        int ans = min(down, right) - dungeon[row][col];

        if (ans > 0) return dp[row][col] = ans;
        else return dp[row][col] = 1;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> dp(n, vector<int> (m, -1));


        return minHP(0, 0, dp, dungeon);
    }
    
};