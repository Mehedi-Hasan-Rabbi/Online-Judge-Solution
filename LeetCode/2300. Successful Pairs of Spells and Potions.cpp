class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = (int) spells.size();
        int m = (int) potions.size();

        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (long long u: spells) {
            int l = 0, r = m - 1, idx = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (u * potions[mid] >= success) {
                    idx = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            ans.push_back( (idx == -1 ? 0 : m - idx) );
        }

        return ans;
    }
};