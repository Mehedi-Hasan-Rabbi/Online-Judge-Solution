class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        unordered_set<int> st;
        for (auto &&u: nums) st.insert(u);

        int longest = 1;
        for (auto &&u: st) {
            if (st.find(u - 1) == st.end()) {
                int consecutive = 1;
                int next = u + 1;
                while (st.find(next) != st.end()) {
                    consecutive++;
                    next++;
                }

                longest = max(longest, consecutive);
            }
        }

        return longest;
    }
};