class Solution {
public:
    int mod = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> a(n + 1, 0);
        a[1] = 1;

        for (int i = 1; i <= n; i++) {
            if (a[i] > 0) {
                int l = i + delay;
                int r = i + forget;

                while (l < min(r, n + 1)) {
                    a[l] = ((a[l] % mod) + (a[i] % mod)) % mod;
                    l++;
                }
                if (r <= n)
                    a[i] = 0;
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = ((ans % mod) + (a[i] % mod)) % mod;
        }

        return ans;
    }
};