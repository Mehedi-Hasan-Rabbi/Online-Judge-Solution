class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        nums.push_back(INT32_MIN);
        int n = (int) nums.size();
        vector<int> sz;

        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i])
                cnt++;
            else {
                sz.push_back(cnt);
                cnt = 1;
            }
        }

        int ans = *max_element(sz.begin(), sz.end()) / 2;

        for (int i = 1; i < (int) sz.size(); i++) {
            int val = min(sz[i - 1], sz[i]);

            ans = max(ans, val);
        }

        return ans;
    }
};