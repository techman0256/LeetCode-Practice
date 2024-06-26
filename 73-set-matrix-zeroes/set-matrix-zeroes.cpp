class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int rows = 0, cols = 0;


        for (int i=0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    if ( i == 0 ) {
                        rows = 1;
                    } 
                    if ( j == 0 ) {
                        cols = 1;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i=1; i < n; i++) {
            if (matrix[i][0] == 0) {
                for (int j=1; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j=1; j < m; j++) {
            if (matrix[0][j] == 0) {
                for (int i=1; i < n; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (cols == 1) {
            for (int i=0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
        if (rows == 1) {
            for (int i=0; i < m; i++) {
                matrix[0][i] = 0;
            }
        }

    }
};