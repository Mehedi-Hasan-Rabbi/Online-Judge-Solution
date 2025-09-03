class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = (int) points.size();
        int ans = 0;

        auto cmp = [&](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            else
                return a[1] > b[1];
        };

        sort(points.begin(), points.end(), cmp);

        for (int i = 0; i < n; i++) {
            int alice_x = points[i][0];
            int alice_y = points[i][1];

            int lower_y = INT32_MIN;
            for (int j = i + 1; j < n; j++) {
                int bob_x = points[j][0];
                int bob_y = points[j][1];

                if (bob_y > alice_y) continue;
                if (bob_y > lower_y) {
                    ans++;
                    lower_y = bob_y;
                }
            }
        }

        return ans;
    }
};