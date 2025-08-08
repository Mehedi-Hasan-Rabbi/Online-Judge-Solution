class Solution {
public:
    vector<vector<int>> op = { {4, 0}, {3, 1}, {2, 2}, {1, 3} };
    vector<vector<double>> dp;

    double prob (int a, int b) {
        if (a == 0 and b > 0) return 1.0;       // A is empty but B is not
        if (a == 0 and b == 0) return 0.5;      // A and B both are empty
        if (a > 0 and b == 0) return 0.0;       // A si not empty but B is empty
        if (dp[a][b] > -0.5) return dp[a][b];   // Memorization

        double ans = 0.0;
        for (int i = 0; i < 4; i++) {
            int aa = max(0, (a - op[i][0]));
            int bb = max(0, (b - op[i][1]));

            ans += 0.25 * prob( aa, bb );       // since each operation has 1 / 4 = 0.25 probability
        }

        return dp[a][b] = ans;
    }

    double soupServings(int n) {        
        int serve = (n / 25) + (n % 25 != 0); // Ceil Value

        if (serve >= 200) return 1;

        dp.assign(n + 5, vector<double>(n + 5, -1.0));

        double ans = (prob(serve, serve));
        return ans;
    }
};