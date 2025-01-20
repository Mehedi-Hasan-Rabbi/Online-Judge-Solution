// Solution in both DFS and BFS
class Solution {
public:
    int dx[4] = {+1, -1, 0, 0};
    int dy[4] = {0, 0, -1, +1};

    vector<vector<int>> vis;
    set<vector<int>> ans;

    void dfs_up_left(int row, int col, int m, int n,
                     vector<vector<int>>& grid) {
        vis[row][col] = 2;

        for (int i = 0; i < 4; i++) {
            int x = row + dx[i];
            int y = col + dy[i];

            if ((0 <= x and x <= m - 1) and (0 <= y and y <= n - 1) and
                vis[x][y] == 0 and grid[x][y] >= grid[row][col]) {
                dfs_up_left(x, y, m, n, grid);
            }
        }
    }

    void dfs_down_right(int row, int col, int m, int n,
                        vector<vector<int>>& grid) {
        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int x = row + dx[i];
            int y = col + dy[i];

            if ((0 <= x and x <= m) and (0 <= y and y <= n) and
                vis[x][y] == 0 and grid[x][y] >= grid[row][col]) {
                dfs_down_right(x, y, m, n, grid);
            }

            if ((0 <= x and x <= m) and (0 <= y and y <= n) and
                vis[x][y] == 2 and grid[x][y] >= grid[row][col]) {
                ans.insert({x, y});
                dfs_down_right(x, y, m, n, grid);
            }
        }
    }

    void bfs_up_left(int row, int col, int m, int n,
                     vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({row, col});

        vis[row][col] = 2;

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = r + dx[i];
                int y = c + dy[i];

                if ((0 <= x and x <= m - 1) and (0 <= y and y <= n - 1) and
                    vis[x][y] == 0 and grid[x][y] >= grid[r][c]) {
                    vis[x][y] = 2;
                    q.push({x, y});
                }
            }
        }
    }

    void bfs_down_right(int row, int col, int m, int n,
                        vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({row, col});

        vis[row][col] = 1;

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = r + dx[i];
                int y = c + dy[i];

                if ((0 <= x and x <= m) and (0 <= y and y <= n) and
                    vis[x][y] == 0 and grid[x][y] >= grid[r][c]) {
                    vis[x][y] = 1;
                    q.push({x, y});
                }

                if ((0 <= x and x <= m) and (0 <= y and y <= n) and
                    vis[x][y] == 2 and grid[x][y] >= grid[r][c]) {
                    vis[x][y] = 1;
                    ans.insert({x, y});
                    q.push({x, y});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // Adding extra row and col with value 0
        for (int i = 0; i < m; i++)
            heights[i].push_back(0);

        vector<int> newRow(n + 1, 0);
        heights.push_back(newRow);

        vis.assign(m + 1, vector<int>(n + 1, 0));

        // Traversing from up and left side of the grid to check non-incresing
        // connected component and mark them as 2 in "vis" vector
        for (int row = 0; row < m; row++) {
            if (vis[row][0] == 0)
                // dfs_up_left(row, 0, m, n, heights);
                bfs_up_left(row, 0, m, n, heights);
        }
        for (int col = 0; col < n; col++) {
            if (vis[0][col] == 0)
                // dfs_up_left(0, col, m, n, heights);
                bfs_up_left(0, col, m, n, heights);
        }

        // Traversing from down and up side of the grid to check non-incresing
        // connected component that connects (find 2 in "vis") with the left-up
        // side.
        for (int row = 0; row <= m; row++) {
            if (vis[row][n] == 0)
                dfs_down_right(row, n, m, n, heights);
                // bfs_down_right(row, n, m, n, heights);
        }
        for (int col = 0; col <= n; col++) {
            if (vis[m][col] == 0)
                dfs_down_right(m, col, m, n, heights);
                // bfs_down_right(m, col, m, n, heights);
        }

        vector<vector<int>> flow_from_cell;
        for (auto u : ans) {
            flow_from_cell.push_back(u);
        }

        return flow_from_cell;
    }
};