class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        int ans = 0;
        for (int i = 0; i + 2 < nums.size(); i++) {
            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];

            if (a < b + c)
                ans = max(ans, (a + b + c));
        }

        return ans;
    }
};