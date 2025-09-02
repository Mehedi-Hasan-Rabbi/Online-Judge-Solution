class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = (int) points.size();
        int ans = 0;

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            else
                return a[0] < b[0];
        });

        for (int one = n - 1; one >= 0; one--) {
            for (int two = one - 1; two >= 0; two--) {
                int x1 = points[one][0], y1 = points[one][1];
                int x2 = points[two][0], y2 = points[two][1];

                if (y2 < y1) continue;

                bool ok = true;
                for (int i = 0; i < n; i++) {
                    if (i != one and i != two) {
                        if ( (min(x1, x2) <= points[i][0] and points[i][0] <= max(x1, x2)) and
                            (min(y1, y2) <= points[i][1] and points[i][1] <= max(y1, y2)) ) {
                                ok = false;
                            }
                    }
                }
                if (ok) ans++;
            }
        }

        return ans;
    }
};