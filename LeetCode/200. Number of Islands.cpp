class Solution {
public:
    int dx[4] = {+1, -1, 0, 0};
    int dy[4] = {0, 0, -1, +1};
    vector<vector<bool>> vis;

    // Using Depth First Search
    // void dfs(int row, int col, int m, int n, vector<vector<char>>& grid) {
    //     vis[row][col] = true;

    //     for (int i = 0; i < 4; i++) {
    //         int x = row + dx[i];
    //         int y = col + dy[i];

    //         if ((0 <= x and x <= m - 1) and 
    //             (0 <= y and y <= n - 1) and
    //             vis[x][y] == false and grid[x][y] == '1')
    //             dfs(x, y, m, n, grid);
    //     }
    // }

    // Using Breadth-First Search
    void bfs(int row, int col, int m, int n, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;

        q.push({row, col});
        vis[row][col] = true;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = r + dx[i];
                int y = c + dy[i];

                if ((0 <= x and x <= m - 1) and 
                    (0 <= y and y <= n - 1) and
                    vis[x][y] == false and grid[x][y] == '1') {

                    vis[x][y] = true;        
                    q.push({x, y});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vis.assign(m, vector<bool>(n, false));

        int ans = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '1' and vis[row][col] == false) {
                    ans++;

                    // dfs(row, col, m, n, grid);
                    bfs(row, col, m, n, grid);
                }
            }
        }

        return ans;
    }
};