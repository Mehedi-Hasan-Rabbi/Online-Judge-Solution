class Solution {
public:
    int dx[4] = {+1, -1, 0, 0};
    int dy[4] = {0, 0, -1, +1};

    vector<vector<bool>> vis;
    int component = 0;

    void dfs(int row, int col, int m, int n, vector<vector<int>>& grid) {
        vis[row][col] = true;

        component++;
        for (int i = 0; i < 4; i++) {
            int x = row + dx[i];
            int y = col + dy[i];

            if ((0 <= x and x <= m - 1) and (0 <= y and y <= n - 1) and
                vis[x][y] == false and grid[x][y] == 1)
                dfs(x, y, m, n, grid);
        }
    }

    void bfs(int row, int col, int m, int n, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        q.push({row, col});
        component++;
        vis[row][col] = true;

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = r + dx[i];
                int y = c + dy[i];

                if ((0 <= x and x <= m - 1) and (0 <= y and y <= n - 1) and
                    vis[x][y] == false and grid[x][y] == 1) {

                    vis[x][y] = true;
                    q.push({x, y});
                    component++;
                }
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vis.assign(m, vector<bool>(n, false));

        vector<int> connected_components;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1 and vis[row][col] == false) {
                    component = 0;
                    dfs(row, col, m, n, grid);
                    // bfs(row, col, m, n, grid);

                    connected_components.push_back(component);
                }
            }
        }

        // If the connected_components vector is empty, calling max_element will
        // result in undefined behavior, because you're trying to dereference an
        // invalid iterator. To avoid this, you need to check if the vector
        // connected_components is empty before attempting to get the maximum
        // element.
        if (connected_components.empty()) {
            return 0; // If there are no components (no islands), return 0
        }

        return *max_element(connected_components.begin(),
                            connected_components.end());
    }
};