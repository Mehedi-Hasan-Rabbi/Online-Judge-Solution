class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;

        while (l < r) {
            int mn = min(height[l], height[r]);
            int res = mn * (r - l);
            ans = max(res, ans);

            if (height[l] <= height[r]) l++;
            else if (height[l] > height[r]) r--;
        }

        return ans;
    }
};