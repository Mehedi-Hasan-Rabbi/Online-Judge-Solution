class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = (int) energy.size();

        vector<bool> vis(n, false);
        for (int i = n - k - 1; i >= 0; i--) {
            if (vis[i] == false) {
                int j = i;
                while (j >= 0) {
                    vis[j] = true;
                    energy[j] = energy[j] + energy[j + k];
                    j = j - k;
                }
            }
        }

        return *max_element(energy.begin(), energy.end());
    }
};