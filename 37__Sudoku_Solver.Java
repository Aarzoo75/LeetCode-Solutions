class Solution {
    public void solveSudoku(char[][] board) {
        solve(board);
    }
    public boolean solve(char[][] board) {
        // traverse the board
        for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 9; j++) {
              // if you find a empty index
            if (board[i][j] == '.') {
                // fill it with a valid digit
              for (char c = '1'; c <= '9'; c++) {
                  // check for validity
                if (isValid(i, j, board, c)) {
                    // if valid then fill it 
                  board[i][j] = c;
                    // transfer the updated board to the next recursive call
                  if (solve(board))
                    return true;
                  else
                    board[i][j] = '.';
                }
              }
              return false;
            }
          }
        }
        return true;
    }
    
    // function to check if digit is valid or not
    public boolean isValid(int row, int col, char[][] board, char ch) {
        for (int i = 0; i < 9; i++) {
            // traverse through the columns
            if (board[i][col] == ch)
                return false;
            // traverse through the rows
            if (board[row][i] == ch)
                return false;
            // traverse through the 3x3 sub-box
			// the expression (3 * (row / 3) + i / 3) evaluates to the row numbers of that 3×3 submatrix
			// the expression (3 * (col / 3) + i % 3) evaluates to the column numbers
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
                return false;
        }
        return true;
    }
}