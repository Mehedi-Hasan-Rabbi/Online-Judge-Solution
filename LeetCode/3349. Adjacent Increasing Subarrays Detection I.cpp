class Solution {
    bool check (vector<int>& nums, int start, int end) {
        bool ans = true;
        
        for (int i = start + 1; i <= end; i++)
            if (nums[i - 1] >= nums[i])
                ans = false;

        return ans;
    }

public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = (int) nums.size();

        for (int i = 0; i + (2 * k - 1) < n; i++) {
            bool first = check(nums, i, i + k - 1);
            bool second = check(nums, i + k, i + 2 * k - 1);

            if (first && second) {
                return true;
            }
        }

        return false;
    }
};