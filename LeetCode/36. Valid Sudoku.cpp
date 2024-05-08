class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> st;

        // Check row is valid
        for (int row = 0; row < 9; row++)
        {
            int cnt = 0;
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] >= '1' and board[row][col] <= '9') {
                    cnt++;
                    st.insert(board[row][col]);
                }
            }
            if (st.size() != cnt) return false;
            cnt = 0;
            st.clear();
        }

        // Check col is valid
        for (int col = 0; col < 9; col++)
        {
            int cnt = 0;
            for (int row = 0; row < 9; row++)
            {
                if (board[row][col] >= '1' and board[row][col] <= '9') {
                    cnt++;
                    st.insert(board[row][col]);
                }
            }
            if (st.size() != cnt) return false;
            cnt = 0;
            st.clear();
        }

        // Check 3X3 sub-boxes
        for (int boxRow = 0; boxRow < 3; boxRow++) // Total 3 row. Each row has 3 sub-box
        {
            for (int box = 0; box < 3; box++) // Select box in a row
            {
                int row_start = boxRow * 3, col_start = box * 3;
                int row_end = row_start + 3, col_end = col_start + 3;

                int cnt = 0, row = row_start, col = col_start;
                while (row < row_end) {
                    while (col < col_end) {
                        if (board[row][col] >= '1' and board[row][col] <= '9') {
                            cnt++;
                            st.insert(board[row][col]);
                        }
                        col++;
                    }
                    col = col_start;
                    row++;
                }
                if (st.size() != cnt) return false;
                cnt = 0;
                st.clear();
            }
        }

        // If all OK
        return true;
    }
};