// Solution - 1
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

// Solution - 2
class Solution {
public:
    int n;
    int dx[3], dy[3];
    vector<vector<int>> dp;

    int find_max (int row, int col, int move_left, vector<vector<int>>& fruits) {
        if (row == n - 1 and col == n - 1) {
            if (move_left == 0) return 0; // Found a path with valid move
            else return INT_MIN; // Did not found a path with valid move
        }
        if (move_left == 0) return INT_MIN; // Used all move but could not found path
        if (dp[row][col] != -1) return dp[row][col];

        // maxFruits = INT_MIN, Because If we can't find and valid path then maxFruits value will not change and that means no path found.

        int maxFruits = INT_MIN, collectedFruits = fruits[row][col];
        for (int i = 0; i < 3; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if ( (0 <= newRow and newRow < n) and (0 <= newCol and newCol < n) ) {
                int val = find_max(newRow, newCol, move_left - 1, fruits);

                if (val != INT_MIN)
                    maxFruits = max(maxFruits, collectedFruits + val);
            }
        }

        return dp[row][col] = maxFruits;
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = (int) fruits.size();
        int ans = 0;

        // Child (0, 0) --> TopLeft
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }

        // Child (0, n - 1) --> TopRight
        dp.assign(n, vector<int>(n, -1));
        dx[0] = +1; dx[1] = +1; dx[2] = +1;
        dy[0] = -1; dy[1] = 0; dy[2] = +1;

        ans += find_max(0, n - 1, n - 1, fruits);

        // Child (n - 1, 0) --> BottomLeft
        dp.assign(n, vector<int>(n, -1));
        dx[0] = -1; dx[1] = 0; dx[2] = +1;
        dy[0] = +1; dy[1] = +1; dy[2] = +1;

        ans += find_max(n - 1, 0, n - 1, fruits);

        return ans;
    }

    // Editorial (Concept): https://www.youtube.com/watch?v=wTBrGvEU8mk
};