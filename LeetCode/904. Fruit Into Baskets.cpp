class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = (int) fruits.size();

        if (n == 1) return 1;

        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            if (fruits[i] != fruits[0]) {
                r = i;
                break;
            }
        }
        int ans = r - l + 1;

        int first = fruits[l], second = fruits[r];

        for (int i = r + 1; i < n; i++) {
            if (fruits[i] == first or fruits[i] == second) {
                r = i;
                ans = max(ans, (r - l + 1));
            }
            else {
                first = fruits[i - 1], second = fruits[i];

                l = i - 1, r = i;
                for (int j = l; j >= 0; j--) {
                    if (fruits[j] == fruits[l]) l = j;
                    else break;
                }

                ans = max(ans, (r - l + 1));
            }
        }

        return ans;
    }
};