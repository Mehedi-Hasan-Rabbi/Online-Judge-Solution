class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;

        for (auto &u: operations) {
            if (u == "++X" or u == "X++")
                ans++;
            else
                ans--;
        }

        return ans;
    }
};