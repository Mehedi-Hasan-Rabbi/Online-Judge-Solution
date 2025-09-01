class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve (vector<vector<char>>& board) {
        // Try to find out empty cell
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    // When an empty cell is found try to put value from 1 to 9
                    for (char val = '1'; val <= '9'; val++) {
                        // Now check if it is possible to put this value
                        if (isPossible(board, row, col, val)) {
                            board[row][col] = val;

                            // Now check if this value is the final valid number 
                            if (solve(board) == true)
                                return true;
                            // If it is not the final valid number then again blank the cell
                            else
                                board[row][col] = '.';
                            
                        }
                    }
                    // The current board state is unsolvable with the choices made earlier. (Backtrack)
                    return false;
                }
            }
        }

        // We have check all row and col. And Question says "It is guaranteed that the input board has only one solution."
        // Then we must find a soltion after checking all possible combination
        return true;
    }

    bool isPossible (vector<vector<char>>& board, int x, int y, char val) {
        // Check Vertical
        for (int row = 0; row < 9; row++) {
            if (board[row][y] == val)
                return false;
        }
        // Check Horizontal
        for (int col = 0; col < 9; col++) {
            if (board[x][col] == val)
                return false;
        }
        // Check 3X3 Subgrid
        int srow = (x / 3) * 3; // Starting row of Subgrid
        int scol = (y / 3) * 3; // Starting col of Subgrid

        for (int row = srow; row <= srow + 2; row++) {
            for (int col = scol; col <= scol + 2; col++) {
                if (board[row][col] == val)
                    return false;
            }
        }

        // Value meet the condition row-wise, col-wise and Subgrid-wise
        return true;
    }
};
/* 
    Time Complexity:
    ------------------------------------------------------- 
        We are trying to fill every empty cell with a number.
        Each cell has 9 choices.

        O(9^numEmplyCells)

        Depth of recursion:
            1. In the worst case, there are 81 empty cells.
            2. So the naive upper bound is: O(9^81) (Total 81 Cells) which is astronomically large.

        But in practice:
            1. Constraints (isPossible) prune most invalid paths early.
            2. The search space is drastically reduced.
            3. On standard Sudoku boards, the solver runs very efficiently.

        👉 So the theoretical worst case: O(9^81)
        👉 The practical case (with pruning): solvable within milliseconds.

    Space Complexity:
    -----------------------------------------------------
        O(1) Because we didn't use any extra memory.
*/