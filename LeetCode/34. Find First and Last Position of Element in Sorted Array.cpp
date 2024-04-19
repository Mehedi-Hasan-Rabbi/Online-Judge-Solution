// Solution 1 (Runtime: 0ms; Memory: 15.96MB)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        bool isExists = binary_search(nums.begin(), nums.end(), target);
        int firstOc = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int lastOc = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (isExists)
            return { firstOc, lastOc - 1 };
        else
            return { -1, -1 };
    }
};

// Solution 2 (Runtime: 3ms; Memory: 16.00MB)
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int l = 0, r = nums.size() - 1;
//         int firstOc = nums.size();
//         while(l <= r) {
//             int mid = l + (r - l) / 2;
//             if (nums[mid] == target) firstOc = min(mid, firstOc);

//             if (nums[mid] >= target) r = mid - 1;
//             else l = mid + 1;
//         }

//         l = 0, r = nums.size() - 1;
//         int lastOc = -1;
//         while(l <= r) {
//             int mid = l + (r - l) / 2;
//             if (nums[mid] == target) lastOc = max(mid, lastOc);

//             if (nums[mid] <= target) l = mid + 1;
//             else r = mid - 1;
//         }

//         if (firstOc == nums.size() and lastOc == -1) return { -1, -1 };
//         else return { firstOc, lastOc };
//     }
// };
