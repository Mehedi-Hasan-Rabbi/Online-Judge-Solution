class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int row = heightMap.size();
        int col = heightMap[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));
        priority_queue< pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> boundary;

        // Push all border values of the grid into the queue
        for (int c = 0; c < col; c++) {
            boundary.push( {heightMap[0][c], {0, c}} );             // {height, {row, col}}
            boundary.push( {heightMap[row - 1][c], {row - 1, c}} );
            vis[0][c] = true, vis[row - 1][c] = true;
        }
        for (int r = 0; r < row; r++) {
            boundary.push( {heightMap[r][0], {r, 0}} );             // {height, {row, col}}
            boundary.push( {heightMap[r][col - 1], {r, col - 1}} );
            vis[r][0] = true, vis[r][col - 1] = true;
        }

        // Go deeper until height is less then boundary.top().first
        int ans = 0;
        int minBoundHeight = 0;     // Minimum height among all height in the boundary
        int dx[4] = {+1, -1, 0, 0};
        int dy[4] = {0, 0, -1, +1};
        
        while (!boundary.empty())
        {
            int height = boundary.top().first;
            int r = boundary.top().second.first;
            int c = boundary.top().second.second;
            boundary.pop();

            // Updat minimum height among all height in the boundary
            minBoundHeight = max(minBoundHeight, height);

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if ( (0 <= nr and nr < row) and (0 <= nc and nc < col) and vis[nr][nc] == false ) {
                    boundary.push({heightMap[nr][nc], {nr, nc}});
                    vis[nr][nc] = true;

                    if (heightMap[nr][nc] < minBoundHeight)
                        ans += minBoundHeight - heightMap[nr][nc];
                }
            }
        }

        return ans;
    }
};
// Editorial: https://www.youtube.com/watch?v=QvQiQcLCQ4Y