class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                ans = mid;
                break;
            }
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        return ans;
    }
};