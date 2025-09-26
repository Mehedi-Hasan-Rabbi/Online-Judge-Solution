class Solution {
    vector<vector<int>> dp;
public:
    int solve (int row, int col, vector<vector<int>>& triangle) {
        if (row == triangle.size() - 1) return triangle[row][col];
        if (dp[row][col] != INT32_MAX) return dp[row][col];
        
        int ans = triangle[row][col];

        int left = solve(row + 1, col, triangle);
        int right = solve(row + 1, col + 1, triangle);
            
        ans += min(left, right);
        
        return dp[row][col] = ans;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Assing INT32_MAX. Because -10^4 <= triangle[i][j] <= 10^4
        dp.assign(n + 5, vector<int>(n + 5, INT32_MAX));

        int ans = solve(0, 0, triangle);
        // Or,
        // ans = dp[0][0]; 
        return ans;
    }
};