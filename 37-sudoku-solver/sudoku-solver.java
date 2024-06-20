import java.util.ArrayList;
import java.util.List;

public class Solution {
   
    private boolean check(int num, int row, int col, char[][] board) {
        for (int i = 0; i < 9; i++) {
            if (num == board[row][i] - '0') {
                return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            if (num == board[i][col] - '0') {
                return false;
            }
        }

        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;
        for (int i = boxRow; i < boxRow + 3; i++) {
            for (int j = boxCol; j < boxCol + 3; j++) {
                if (num == board[i][j] - '0') {
                    return false;
                }
            }
        }

        return true;
    }

    private void solve(int idx, char[][] board, List<char[][]> ans) {
        // base case
        if (idx == 81) {
            char[][] solvedBoard = new char[9][9];
            for (int i = 0; i < 9; i++) {
                System.arraycopy(board[i], 0, solvedBoard[i], 0, 9);
            }
            ans.add(solvedBoard);
            return;
        }

        int row = idx / 9;
        int col = idx % 9;
        if (board[row][col] == '.') {
            for (int i = 1; i <= 9; i++) {
                if (check(i, row, col, board)) {
                    board[row][col] = (char) (i + '0');
                    solve(idx + 1, board, ans);
                    board[row][col] = '.';
                }
            }
        } else {
            solve(idx + 1, board, ans);
        }
    }

    public void solveSudoku(char[][] board) {
        List<char[][]> ans = new ArrayList<>();
        solve(0, board, ans);
        if (!ans.isEmpty()) {
            char[][] solvedBoard = ans.get(0);
            for (int i = 0; i < 9; i++) {
                System.arraycopy(solvedBoard[i], 0, board[i], 0, 9);
            }
        }
    }
}