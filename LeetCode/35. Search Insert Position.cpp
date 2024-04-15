class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, lowerBound = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] >= target) {
                // lowerBound = mid;
                // Or, 
                lowerBound = min(lowerBound, mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }

	// Another Solution
	// int lowerBound = (lower_bound(nums.begin(), nums.end(), target)) - nums.begin();
	// On runtime -> Beats 100.00% of users with C++

        return lowerBound;
    }
};