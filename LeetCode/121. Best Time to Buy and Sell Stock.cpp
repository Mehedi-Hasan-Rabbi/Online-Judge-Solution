class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT32_MIN;
        int mn = prices[0];

        for (int i = 0; i < (int)prices.size(); i++) {
            mn = min(prices[i], mn);

            ans = max((prices[i] - mn), ans);
        }

        return (ans > 0 ? ans : 0);
    }
};