class Solution {
public:
    bool seive[1010000];
    vector<int> prime;
    void seiveGen(int limit) {
        limit += 100;
        int sqrtn = sqrt(limit);
        for (int i = 3; i <= sqrtn; i += 2) {
            if (!seive[i >> 1]) {
                for (int j = i * i; j < limit; j += i + i) {
                    seive[j >> 1] = 1;
                }
            }
        }
        prime.push_back(2);
        for (int i = 3; i < limit; i += 2) {
            if (!seive[i >> 1])
                prime.push_back(i);
        }
    }

    vector<int> closestPrimes(int left, int right) {

        seiveGen(1000005);

        int l, r, sz = (int)prime.size();
        for (int i = 0; i < sz; i++) {
            if (left <= prime[i]) {
                l = i;
                break;
            }
        }

        for (int i = sz - 1; i >= 0; i--) {
            if (prime[i] <= right) {
                r = i;
                break;
            }
        }

        vector<pair<int, pair<int, int>>> ans;
        for (int i = l; i < r; i++) {
            int dif = abs(prime[i] - prime[i + 1]);

            ans.push_back({dif, {prime[i], prime[i + 1]}});
        }

        sort(ans.begin(), ans.end());

        int num1 = -1, num2 = -1;
        if (l + 1 <= r)
            num1 = ans[0].second.first, num2 = ans[0].second.second;

        return {num1, num2};
    }
};