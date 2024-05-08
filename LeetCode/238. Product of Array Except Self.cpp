// Solution 1 (Using Suffix and Prefix)
// ------------------------------------------------
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0), suffix(n, 0), ans;

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] * nums[i];
        
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] * nums[i];
        
        for (int i = 0; i < n; i++)
        {
            int mul = 1;
            if (i == 0) mul = suffix[1];
            else if (i == n - 1) mul = prefix[n - 2];
            else mul = prefix[i - 1] * suffix[i + 1]; 
            ans.push_back(mul);
        }

        return ans;
    }
};

// Solution 2 (Not using extra memory)
// -----------------------------------------
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        ans[0] = nums[0];
        for (int i = 1; i < n; i++)
            ans[i] = ans[i - 1] * nums[i];
        
        int suffix = 1;
        for (int i = n - 1; i >= 1; i--)
        {
            ans[i] = ans[i - 1] * suffix;
            suffix = suffix * nums[i];
        }
        ans[0] = suffix;

        return ans;
    }
};