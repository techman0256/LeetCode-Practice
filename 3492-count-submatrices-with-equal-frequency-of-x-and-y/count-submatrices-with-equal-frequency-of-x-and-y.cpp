class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prefix(n, vector<int> (m, 0));
        vector<vector<bool>> x(n, vector<bool> (m, false));

        if (grid[0][0] == 'X') {
            prefix[0][0] = 1;
            x[0][0] = 1;
        }
        else if (grid[0][0] == 'Y') {
            prefix[0][0] = -1;
            x[0][0] = 0;
        }
        else {
            prefix[0][0] = 0;
            x[0][0] = 0;
        }

        for (int i=1; i < m; i++) {
            if (grid[0][i] == 'X') {
                prefix[0][i] = prefix[0][i - 1] + 1;
                x[0][i] = 1;
            } 
            else if (grid[0][i] == 'Y') {
                prefix[0][i] = prefix[0][i - 1] - 1;
                x[0][i] = x[0][i - 1];
            } else {
                prefix[0][i] = prefix[0][i - 1];
                x[0][i] = x[0][i - 1];
            }
        }

        for (int i=1; i < n; i++) {
            if (grid[i][0] == 'X') {
                prefix[i][0] = prefix[i - 1][0] + 1;
                x[i][0] = 1;
            } else if (grid[i][0] == 'Y') {
                prefix[i][0] = prefix[i - 1][0] - 1;
                x[i][0] = x[i - 1][0];
            } else {
                prefix[i][0] = prefix[i - 1][0];
                x[i][0] = x[i - 1][0];
            }
        }

        for (int i=1; i < n; i++) {
            for (int j=1; j < m; j++) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
                x[i][j] = x[i - 1][j] || x[i][j - 1] || x[i - 1][j - 1];
                if (grid[i][j] == 'X') {
                    prefix[i][j] += 1;
                    x[i][j] = 1;
                } else if (grid[i][j] == 'Y') {
                    prefix[i][j] -= 1;
                } 
                
            }
        }
        int cnt = 0;
        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                if (prefix[i][j] == 0 && x[i][j] == 1) {
                    cnt++;
                }

            }
        }


        return cnt;




    }
};