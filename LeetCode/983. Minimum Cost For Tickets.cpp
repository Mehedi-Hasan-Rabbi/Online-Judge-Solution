class Solution {
public:
    int dp[370];

    int findCost(int idx, vector<int>& days, vector<int>& costs,
                 vector<int>& day_pass) {
        if (idx == (int)days.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        int ans = INT32_MAX;
        for (int i = 0; i < 3; i++) {
            int next = days[idx] + day_pass[i] - 1;

            int next_idx = idx;
            while (next_idx < days.size() and days[next_idx] <= next)
                next_idx++;

            int curr_cost =
                costs[i] + findCost(next_idx, days, costs, day_pass);

            ans = min(ans, curr_cost);
        }

        return dp[idx] = ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        vector<int> day_pass = {1, 7, 30};

        int ans = findCost(0, days, costs, day_pass);
        return ans;
    }
};