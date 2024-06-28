class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        int rowStart = 0;
        int rowEnd = n - 1;
        int colStart = 0;
        int colEnd = m - 1;

        while (rowStart <= rowEnd && colStart <= colEnd) {
            for (int i=colStart; i <= colEnd; i++) {
                ans.push_back(matrix[rowStart][i]);
            }
            rowStart++;
            for (int j=rowStart; j <= rowEnd; j++) {
                ans.push_back(matrix[j][colEnd]);
            }
            colEnd--;
            if (rowStart <= rowEnd) {
                for (int j=colEnd; j >= colStart; j--) {
                    ans.push_back(matrix[rowEnd][j]);
                }
                rowEnd--;

            }
            if (colStart <= colEnd) {
                for (int i=rowEnd; i >= rowStart; i--) {
                    ans.push_back(matrix[i][colStart]);
                }
                colStart++;
            }
        }

        return ans;
    }
};