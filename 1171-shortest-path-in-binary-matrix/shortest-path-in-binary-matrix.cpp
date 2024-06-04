class Solution {
public:
    // typedef pair<pair<int, int>, int> 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dis(n, vector<int> (n, INT_MAX));
        queue< pair< pair<int, int>, int> > bfs;
        if (grid[0][0] == 1) return -1;
        bfs.push({{0, 0}, 1});
        dis[0][0] = 1;

        int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
        int dy[] = { 0, -1, 0, 1, -1, 1, -1, 1 };

        while ( !bfs.empty() ) {
            int u_x = bfs.front().first.first;
            int u_y = bfs.front().first.second;
            int len = bfs.front().second;
            bfs.pop();

            for (int i=0; i < 8; i++) {
                int v_x = u_x + dx[i];
                int v_y = u_y + dy[i];

                if (v_x >= 0 && v_y >= 0 && v_x < n && v_y < n && grid[v_x][v_y] == 0 && dis[v_x][v_y] > len + 1) {
                    dis[v_x][v_y] = len + 1;
                    bfs.push({{v_x, v_y}, 1 + len});
                } 
            }
        }


        if (dis[n - 1][n - 1] == INT_MAX) return -1;
        
        return dis[n  - 1][n - 1];


    }
};