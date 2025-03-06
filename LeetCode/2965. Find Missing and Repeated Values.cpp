class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n * n + 1, 0);

        for (auto vec: grid) {
            for (auto u: vec)
                freq[u]++;
        }

        int twice = -1, missing = -1;
        for (int i = 1; i <= (n * n); i++) {
            if (freq[i] == 0) missing = i;
            if (freq[i] == 2) twice = i;
        }

        return {twice, missing};
    }
};