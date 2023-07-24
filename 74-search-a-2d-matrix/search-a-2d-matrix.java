class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;

        int x = 0;
        int y = m - 1;

        while (x >=0 && y >= 0 && x < n && y < m) {
            if (matrix[x][y] == target) return true;
            
            if (target < matrix[x][y]) {
                y--;
            } else {
                x++;
            }
        }

        return false;
    }
}