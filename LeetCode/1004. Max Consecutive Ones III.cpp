// Solution 1: Using Binary Search
// -------------------------------------
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        nums.insert(nums.begin() + 0, 0);
        int n = nums.size();

        // Prefix sum
        for (int i = 1; i < n; i++)
            nums[i] = nums[i - 1] + nums[i];

        int ans = 0;

        for (int i = 1; i < n; i++) {
            int l = i, r = n - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;

                int val = nums[mid] - nums[i - 1];
                int len = mid - i + 1;
                int flip_need = len - val;

                if (flip_need <= k) {
                    ans = max(ans, len);
                    l = mid + 1;
                }
                else r = mid - 1;
            }
        }

        return ans;
    }
};

// Solution 2: Sliding Window
// ---------------------------------------------