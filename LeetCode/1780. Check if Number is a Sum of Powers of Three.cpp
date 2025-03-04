class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> pow;
        int val = 1;
        for (int i = 0; val <= 1e7; i++) {
            pow.push_back(val);
            val = val * 3;
        }

        int sz = pow.size();
        for (int i = sz - 1; i >= 0; i--) {
            if (n >= pow[i])
                n -= pow[i];
            
            if (n == 0) return true;
        }

        return false;
    }
};