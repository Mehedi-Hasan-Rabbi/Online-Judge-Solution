class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> pref_max(n, 0), suff_max(n, 0);
        pref_max[0] = nums[0], suff_max[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++)
            pref_max[i] = max(pref_max[i - 1], nums[i]);
        for (int i = n - 2; i >= 0; i--)
            suff_max[i] = max(suff_max[i + 1], nums[i]);

        long long ans = INT64_MIN;
        for (int i = 1; i < n - 1; i++) {
            long long val = ((long long)pref_max[i - 1] - (long long)nums[i]) *
                            (long long)suff_max[i + 1];
            ans = max(ans, val);
        }

        return (ans < 0 ? 0 : ans);
    }
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
};