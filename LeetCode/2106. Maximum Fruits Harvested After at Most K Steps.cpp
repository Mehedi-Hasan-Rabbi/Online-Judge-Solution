class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = (int)fruits.size();

        // Insert startPos if it does not exists in the fruits vector.
        bool exists = false;
        for (int i = 0; i < n; i++) {
            if (fruits[i][0] == startPos)
                exists = true;
        }
        if (!exists) {
            fruits.push_back({startPos, 0});
            sort(fruits.begin(), fruits.end());
            n++;
        }

        // Find the starting index and do prefix sum
        vector<int> axis(n + 5, 0), amount(n + 5, 0);
        int startIdx = -1;
        for (int i = 1; i <= n; i++) {
            axis[i] = fruits[i - 1][0];
            amount[i] = fruits[i - 1][1];

            if (axis[i] <= startPos)
                startIdx = i;

            amount[i] = amount[i - 1] + amount[i];
        }

        int ans = 0;

        // Move left and then move right
        for (int i = 1; i <= startIdx; i++) {
            if (startPos - axis[i] > k)
                continue;

            int val = amount[startIdx] - amount[i - 1];
            int move = k - (startPos - axis[i]);

            int l = startIdx + 1, r = n, idx = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;

                int dis = axis[mid] - axis[i];

                if (dis <= move) {
                    idx = mid;
                    l = mid + 1;
                } else
                    r = mid - 1;
            }

            if (idx != -1)
                val = amount[idx] - amount[i - 1];
            ans = max(ans, val);
        }

        // Move right and then move left
        for (int i = startIdx; i <= n; i++) {
            if (axis[i] - startPos > k)
                continue;

            int val = amount[i] - amount[startIdx - 1];
            int move = k - (axis[i] - startPos);

            int l = 1, r = startIdx - 1, idx = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;

                int dis = axis[i] - axis[mid];

                if (dis <= move) {
                    idx = mid;
                    r = mid - 1;
                } else
                    l = mid + 1;
            }

            if (idx != -1)
                val = amount[i] - amount[idx - 1];
            ans = max(ans, val);
        }

        return ans;
    }
};