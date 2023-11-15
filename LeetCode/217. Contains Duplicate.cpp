class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        for (auto u: nums) st.insert(u);

        if (nums.size() == st.size()) return false;
        else return true;
    }
};