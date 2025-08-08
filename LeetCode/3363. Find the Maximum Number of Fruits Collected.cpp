class Solution {
public:
    int n;
    int dx[3], dy[3];
    vector<vector<int>> dp;

    int TopRightChild (int row, int col, vector<vector<int>>& fruits) {
        if (row == n - 1 and col == n - 1) return 0; // Reached target cell
        if (row >= col) return 0; // Move NOT-allowed
        if (dp[row][col] != -1) return dp[row][col];

        int maxFruit = 0, collectedFruit = fruits[row][col];
        for (int i = 0; i < 3; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if ((0 <= newRow and newRow < n) and (0 <= newCol and newCol < n)) {
                int val = collectedFruit + TopRightChild(newRow, newCol, fruits);
                maxFruit = max(maxFruit, val);
            }
        }

        return  dp[row][col] = maxFruit;
    }

    int DownRightChild (int row, int col, vector<vector<int>>& fruits) {
        if (row == n - 1 and col == n - 1) return 0; // Reached target cell
        if (row <= col) return 0; // Move NOT-allowed
        if (dp[row][col] != -1) return dp[row][col];

        int maxFruit = 0, collectedFruit = fruits[row][col];
        for (int i = 0; i < 3; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if ((0 <= newRow and newRow < n) and (0 <= newCol and newCol < n)) {
                int val = collectedFruit + DownRightChild(newRow, newCol, fruits);
                maxFruit = max(maxFruit, val);
            }
        }

        return  dp[row][col] = maxFruit;
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = (int) fruits.size();
        int ans = 0;

        // Child (0, 0)
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }

        // Child (0, n - 1)
        dp.assign(n, vector<int>(n, -1));
        dx[0] = +1; dx[1] = +1; dx[2] = +1;
        dy[0] = -1; dy[1] = 0; dy[2] = +1;

        ans += TopRightChild(0, n - 1, fruits);

        // Child (n - 1, 0)
        dp.assign(n, vector<int>(n, -1));
        dx[0] = -1; dx[1] = 0; dx[2] = +1;
        dy[0] = +1; dy[1] = +1; dy[2] = +1;

        ans += DownRightChild(n - 1, 0, fruits);

        return ans;
    }

    // Editorial (Just take the concept): https://www.youtube.com/watch?v=HkjfJKlxS9U
};