// Approach - 1 (Sorting) O(nlogn)
// ------------------------------------------
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        return nums[ nums.size() - k ];
    }
};

// Approach - 2 (Minimum Heap) O(nlogk)
// ------------------------------------------
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto num: nums) {
            minHeap.push(num);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};


// Approach - 3 (Quick Select) Avg: O(n), Worst: O(n^2)
// This will give Time Limit Exceeded (43/44 testcases passed) in new test case on LeetCode
// Explanation (NeetCode): https://www.youtube.com/watch?v=XEmy13g1Qxc
// Try to see editorial of NeetCode there is an Optimal version of quick select.
// Link: https://neetcode.io/problems/kth-largest-element-in-an-array
// ----------------------------------------------------------------------------------------
class Solution {
    // Using more like quick sort approch but not sorting.
    int quickSelect (vector<int>& nums, int left, int right, int k) {
        int pivot = nums[right];
        int p = left;

        // All the element in left side is <= pivot
        // All the element in right side is > pivot
        for (int i = left; i < right; i++) {
            if (nums[i] <= pivot) {
                swap(nums[p], nums[i]);
                p++;
            }
        }
        swap(nums[p], nums[right]);

        if (p > k) {
            return quickSelect (nums, left, p - 1, k);
        }
        else if (p < k) {
            return quickSelect (nums, p + 1, right, k);
        }
        else {
            return nums[p];
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        // Index of the largest element
        k = nums.size() - k;

        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};
