class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int curr = nums.back();
        long long ans = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {   
            if (nums[i] <= curr) curr = nums[i];
            else {
                int part = ceil( (double) nums[i] / curr );
                ans += (part - 1);
                curr = nums[i] / part;
            }
        }
        
        return ans;
    }
};