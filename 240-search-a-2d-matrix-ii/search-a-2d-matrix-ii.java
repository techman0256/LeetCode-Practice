class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        int x = 0, y = m - 1;
        while (x < n && y >= 0) {
            if (target == matrix[x][y]) {
                return true;
            }

            if (target < matrix[x][y]) {
                y--;
            } else {
                x++;
            }
        }

        return false;
    }
}