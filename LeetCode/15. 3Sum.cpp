// Solution 1: Two-pointer Approch (n^n)
// -------------------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i  = 0; i <= nums.size() - 3; i++)
        {
            if (nums[i] > 0) break;
            else if (i > 0  and nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;

                    while (l < r and nums[l] == nums[l - 1]) l++;
                }
                else if (sum > 0) r--;
                else l++; 
            } 
        }

        return ans;
    }
};



// Solution 2: Using binary search (n^2 * logn)
// -----------------------------------------

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        
        int n = nums.size();
        for (int i = 0; i <= n - 3; i++)
        {
            for (int j = i + 1; j <= n - 2; j++)
            {
                int l = j + 1, r = n - 1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;

                    if (nums[i] + nums[j] + nums[mid] == 0) {
                        ans.insert({nums[i], nums[j], nums[mid]});
                        break;
                    }
                    else if (nums[i] + nums[j] + nums[mid] > 0) r = mid - 1;
                    else l = mid + 1;
                }
            }
        }

        vector<vector<int>> res;
        for (auto u: ans) {
            res.push_back(u);
        }

        return res;
    }
};