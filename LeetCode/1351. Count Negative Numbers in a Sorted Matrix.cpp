class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;

        for (auto &&u: grid) {
            reverse(u.begin(), u.end());
            int l = 0, r = u.size() - 1, idx = u.size();
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (u[mid] >= 0) {
                    idx = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            // Or, use the inbuilt function
            // int idx = lower_bound(u.begin(), u.end(), 0) - u.begin();
            ans += idx;
        }

        return ans;
    }
};