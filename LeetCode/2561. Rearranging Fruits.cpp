class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = (int)basket1.size();

        sort(basket1.begin(), basket1.end());
        sort(basket2.begin(), basket2.end());

        // Indirect Swap: Use the cheapest fruit in both baskets as an
        // intermediary. This involves two swaps.
        int mn = min(basket1[0], basket2[0]) * 2;

        map<int, int> count1, count2, total;
        for (int i = 0; i < n; i++) {
            count1[basket1[i]]++, count2[basket2[i]]++;
            total[basket1[i]]++, total[basket2[i]]++;
        }

        vector<int> swap1, swap2;
        for (auto& [key, val] : count1) {
            if (total[key] % 2 == 1)
                return -1;

            int need = total[key] / 2;
            int have = val;

            if (have > need) {
                while (have != need) {
                    swap1.push_back(key);
                    have--;
                }
            }
        }
        for (auto& [key, val] : count2) {
            if (total[key] % 2 == 1)
                return -1;

            int need = total[key] / 2;
            int have = val;

            if (have > need) {
                while (have != need) {
                    swap2.push_back(key);
                    have--;
                }
            }
        }

        sort(swap2.begin(), swap2.end(), greater<int>());
        long long ans = 0;
        for (int i = 0; i < (int)swap1.size(); i++) {
            int val = min(mn, min(swap1[i], swap2[i]));
            ans += val;
        }

        return ans;
    }
};