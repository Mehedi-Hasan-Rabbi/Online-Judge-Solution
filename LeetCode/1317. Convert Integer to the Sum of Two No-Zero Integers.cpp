class Solution {
public:
    bool checkZero (int n) {
        while (n > 0) {
            if (n % 10 == 0) return true;
            n = n / 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for (int a = 1; a < n; a++) {
            int b = abs(a - n);

            if (!checkZero(a) and !checkZero(b)) {
                ans = {a, b};
                break;
            }
        }

        return ans;
    }
};