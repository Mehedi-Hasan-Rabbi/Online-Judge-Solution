class Solution {
public:
    int dp[305][5005]; // [number of coins][maximun number input]

    int solve(int idx, int total, vector<int> &coin) {
        if (idx == (int) coin.size() or total == 0) {
            if (total == 0)
                return 1;
            else
                return 0;
            // return (total == 0); // In short
        }
        if (dp[idx][total] != -1)
            return dp[idx][total];

        int ans = 0;
        for (int i = 0; i <= total; i++) {
            if (total - (i * coin[idx]) >= 0)
                ans += solve(idx + 1, (total - (i * coin[idx])), coin);
            else
                break;
        }

        return dp[idx][total] = ans;
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(0, amount, coins);
        return ans;
    }
};