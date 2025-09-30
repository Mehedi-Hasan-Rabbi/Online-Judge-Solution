class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums = nums;

        while (newNums.size() != 1) {
            newNums.assign(nums.size() - 1, 0);

            for (int i = 0; i < newNums.size(); i++) {
                newNums[i] = (nums[i] + nums[i + 1]) % 10;
            }

            nums = newNums;
        }

        return newNums[0];
    }
};