class Solution {
public:
    bool isThree(int n) {
        int sq;
        for (int i = 1; i <= n; i++)
        {
            if (i*i >= n) {
                if (i*i == n) sq = i;
                else sq = i - 1;
            }
        }

        int cnt = 0;
        for (int i = 1; i <= sq; i++)
        {
            if (n % i == 0) {
                if (n / i == i) cnt++;
                else cnt = cnt + 2;
            }
        }
        
        bool ans = (cnt == 3);

        return ans;
    }
};