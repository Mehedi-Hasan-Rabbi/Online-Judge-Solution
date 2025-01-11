class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> multiSource;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 2)
                    multiSource.push_back({row, col});
            }
        }

        // Multi source BFS traversal
        vector<vector<int>> level(m, vector<int>(n, -1));
        int dx[4] = {+1, -1, 0, 0};
        int dy[4] = {0, 0, -1, +1};

        queue<pair<int, int>> q;

        for (auto& u : multiSource) {
            q.push({u.first, u.second});
            level[u.first][u.second] = 0;
        }

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = r + dx[i];
                int y = c + dy[i];

                if ((0 <= x and x <= m - 1) and (0 <= y and y <= n - 1) and
                    level[x][y] == -1 and grid[x][y] == 1) {

                    level[x][y] = level[r][c] + 1;
                    q.push({x, y});
                }
            }
        }

        int ans = INT32_MIN;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    if (level[row][col] == -1) {
                        ans = -1;
                        break;
                    } else
                        ans = max(ans, level[row][col]);
                }
            }
            if (ans == -1) break;
        }

        if (ans == INT32_MIN) ans = 0;
        return ans;
    }
};