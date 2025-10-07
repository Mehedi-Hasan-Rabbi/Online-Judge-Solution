class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = (int) rains.size();
        
        unordered_map<int, int> fill;
        set<int> zero;
        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++) {
            int lake = rains[i];
            if (lake == 0) {
                zero.insert(i);
            }
            else {
                if (fill.count(lake)) {
                    auto it = zero.lower_bound(fill[lake]);
                    if (it == zero.end()) return {};

                    ans[*it] = lake;
                    zero.erase(it);
                }

                ans[i] = -1;
                fill[lake] = i;
            }
        }

        return ans;
    }
};