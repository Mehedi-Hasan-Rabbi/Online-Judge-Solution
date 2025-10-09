class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = (int) skill.size();
        int m = (int) mana.size();

        vector<long long> time(n, 0);
        for (int i = 0; i < m; i++) {
            long long val = mana[i];
            for (int j = 0; j < n; j++) {
                // For first wizard
                if (j == 0) time[j] = time[j] + (skill[j] * val);

                // For 2nd to last wizard add time with previous one
                if (j != 0) time[j] = time[j - 1] + (skill[j] * val);

                // Check when the next wizard will finish and adjust it will current wizard.
                if (j + 1 < n) time[j] = max(time[j], time[j + 1]);
            }

            // Now final adjustment according to the last time.
            for (int j = n - 2; j >= 0; j--) {
                time[j] = time[j + 1] - (skill[j + 1] * val);
            }
        }

        return time[n - 1];
    }
};