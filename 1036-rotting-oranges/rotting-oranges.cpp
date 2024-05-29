class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int time = 0, total = 0, cnt = 0;

        queue<pair<int, int>> rott;
        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                if (grid[i][j] != 0) total++;
                if (grid[i][j] == 2 ) rott.emplace(i , j);
            }
        }

        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};


        while ( !rott.empty() ) {
            int k = rott.size();
            cnt += k;

            while (k > 0) {
                int x = rott.front().first;
                int y = rott.front().second;
                rott.pop();

                for (int i=0; i < 4; i++) {
                    // cout << i << endl;
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >=0 && ny >=0 && nx < n && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        rott.emplace(nx, ny);
                    }
                }

                k--;
            }
            if ( !rott.empty() ) {
                time++;
            }

        }

        return total == cnt ? time : -1;
    }
};