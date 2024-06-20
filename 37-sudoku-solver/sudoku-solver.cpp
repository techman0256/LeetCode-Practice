class Solution {
public:
   
    bool check(int num, int row, int col, vector<vector<char>> &board) {
        for (int i=0; i < 9; i++) {
            if ( num == board[row][i] - '0' ) {
                return false;
            }
        }

        for (int i=0; i < 9; i++) {
            if ( num == board[i][col] - '0' ) {
                return false;
            }
        }

        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;
        for (int i=boxRow; i < boxRow + 3; i++) {
            for (int j=boxCol; j < boxCol + 3; j++) {
                if ( num == board[i][j] - '0' ) {
                    return false;
                }
            }
        }

        return true;
    }
    void solve(int idx, vector<vector<char>> &board, vector<vector<char>> &ans) {
        // base case
        if (idx == 81) {  
            for ( auto i : board) {
                ans.push_back(i);
            }     
            return;
        }
        // vector<vector<char>> ans;
        int row = idx / 9;
        int col = idx % 9;
        if ( board[row][col] == '.' ) {
            for ( int i=1; i <= 9; i++ ) {
                if (check(i, row, col, board)) {
                    board[row][col] = i + '0';
                    solve(idx + 1, board, ans);
                    board[row][col] = '.';

                }
            }
        } else {
            solve(idx + 1, board, ans);
        }

        return;       

    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> ans;
        solve(0, board, ans);
        board = ans;

    }
};
//  thought processs
/*
    3 rules
    mechanism to check inner grid

*/