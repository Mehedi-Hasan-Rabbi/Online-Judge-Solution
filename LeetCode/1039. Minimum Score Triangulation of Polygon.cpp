// Video Explanation: https://www.youtube.com/watch?v=Eo4G_LPCgX8&t

// Solution Using only recursion. This will give TLE
/*
class Solution {
public:
    int solve (int i, int j, vector<int>& v) {
        if (i + 1 == j) return 0;

        int ans = INT_MAX;
        for (int k = i + 1; k <= j - 1; k++) {
            int val = v[i] * v[j] * v[k];
            val += solve(i, k, v);
            val += solve(k, j, v);

            ans = min(ans, val);
        }

        return ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int ans = solve(0, n - 1, values);

        return ans;
    }
};
*/

// Solution recursion + memorization. (Top - Down DP)
class Solution {
    vector<vector<int>> dp;
public:
    int solve (int i, int j, vector<int>& v) {
        if (i + 1 == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for (int k = i + 1; k <= j - 1; k++) {
            int val = v[i] * v[j] * v[k];
            val += solve(i, k, v);
            val += solve(k, j, v);

            ans = min(ans, val);
        }

        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        dp.assign(n, vector<int>(n, -1));

        int ans = solve(0, n - 1, values);

        return ans;
    }
};

// Solution Using Bottom-Up DP (Interative)
/* 
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                
                int ans = INT_MAX;
                for (int k = i + 1; k <= j - 1; k++) {
                    int val = values[i] * values[j] * values[k];
                    val += dp[i][k];
                    val += dp[k][j];

                    ans = min(ans, val);
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][n - 1];
    }
};
*/