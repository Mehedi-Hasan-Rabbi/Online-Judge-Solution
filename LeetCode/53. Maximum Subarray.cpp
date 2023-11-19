class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane's algorithm
        int ans = INT_MIN, sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            ans = max(sum, ans);
            if (sum < 0) sum = 0;
        }

        return ans;
    }
};