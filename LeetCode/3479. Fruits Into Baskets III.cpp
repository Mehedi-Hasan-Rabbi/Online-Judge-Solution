class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = (int)baskets.size();

        // Square Root Decomposition approch
        // https://cp-algorithms.com/data_structures/sqrt_decomposition.html
        int len = (int)sqrt(n + .0) + 1;

        vector<int> maxV(len);
        for (int i = 0; i < n; i++) {
            maxV[i / len] = max(maxV[i / len], baskets[i]);
        }

        int totSet = 0;
        for (auto fruit : fruits) {
            int set = 0;
            for (int i = 0; i < (int)maxV.size(); i++) {
                if (maxV[i] >= fruit) {
                    for (int j = i * len; j < min(n, ((i + 1) * len)); j++) {
                        if (baskets[j] >= fruit) {
                            baskets[j] = 0;
                            set = 1;
                            break;
                        }
                    }
                    int mx = -1;
                    for (int j = i * len; j < min(n, ((i + 1) * len)); j++) {
                        mx = max(mx, baskets[j]);
                    }

                    maxV[i] = mx;
                }

                if (set)
                    break;
            }

            totSet += set;
        }

        return (n - totSet);
    }
};