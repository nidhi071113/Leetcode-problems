class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // Look for an empty cell
                if (board[i][j] == '.') {
                    // Try digits from '1' to '9'
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;

                            // Recurse to solve the remaining board
                            if (solve(board) == true)
                                return true;

                            // Backtrack if placing 'c' didn't lead to a solution
                            board[i][j] = '.';
                        }
                    }
                    // If no digit from '1' to '9' is valid, backtrack
                    return false;
                }
            }
        }
        // If all cells are filled, solution is found
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[row][i] == c)
                return false;

            // Check column
            if (board[i][col] == c)
                return false;

            // Check 3x3 sub-box
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
};