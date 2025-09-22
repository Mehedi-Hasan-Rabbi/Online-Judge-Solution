class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(105, 0);
        int mx = 0;
        for (auto u: nums) {
            freq[u]++;
            mx = max(mx, freq[u]);
        }

        int ans = 0;
        for (auto u: nums) {
            if (freq[u] == mx)
                ans++;
        }

        return ans;
    }
};