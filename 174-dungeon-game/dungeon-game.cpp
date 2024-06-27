class Solution {
public:

    int n, m;
    int dp[201][201];
    int f(int i, int j, vector<vector<int>> &dungeon) {

        if(i >= n || j >= m) return 1e9;

        if(i == n-1 && j == m-1) return dungeon[i][j] > 0 ? 1 : 1 - dungeon[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = f(i+1, j, dungeon);
        int right = f(i, j+1, dungeon);

        int ans = min(down, right) - dungeon[i][j];

        return dp[i][j] = ans > 0 ? ans : 1;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size(), m = dungeon[0].size();
        memset(dp, -1, sizeof(dp));
        return f(0,0,dungeon);
    }
};