class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0.00;

        for (int i = 0; i + 2 < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1; j + 1 < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                for (int k = j + 1; k < n; k++) {
                    int x3 = points[k][0];
                    int y3 = points[k][1];

                    // Area of a triangle with points
                    double area = 0.5 * abs((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2)));

                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};