class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = (int)fruits.size();

        vector<bool> vis(n, false);
        int ans = n;

        for (auto fruit : fruits) {
            for (int i = 0; i < n; i++) {
                if (baskets[i] >= fruit and vis[i] == false) {
                    vis[i] = true;
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};