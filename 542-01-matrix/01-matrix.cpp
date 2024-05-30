class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int> (m, 0));
        vector<vector<int>> vis(n, vector<int> (m, 0));

        queue<pair<int, int>> bfs;
        queue<int> dist;

        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                if (mat[i][j] == 0) {
                    bfs.emplace(i , j);
                    dist.push(0);
                    vis[i][j] = 1;
                } else {
                    vis[i][j] = 0;
                }
            }
        }

        while ( !bfs.empty() ) {
            int x = bfs.front().first;
            int y = bfs.front().second;
            int steps = dist.front();
            bfs.pop(), dist.pop();
            ans[x][y] = steps;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int j=0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx >=0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] == 0) {
                    vis[nx][ny] = 1;
                    bfs.emplace(nx, ny);
                    dist.push(steps + 1);
                }
            }
        }

        return ans;
    }
};