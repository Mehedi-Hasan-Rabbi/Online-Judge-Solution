class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + arr[i - 1];
        
        int ans = 0;
        for (int l = 1; l <= n; l += 2)
        {
            for (int i = l; i <= n; i++)
                ans += pref[i] - pref[i - l];
        }

        return ans;
    }
};