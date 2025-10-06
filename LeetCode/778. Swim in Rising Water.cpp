class Solution {
public:
    int dijkstra (vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dx[4] = {+1, -1, 0, 0};
        int dy[4] = {0, 0, -1, +1};

        vector<vector<int>> dist(m, vector<int>(n, INT32_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        while (!pq.empty()) {
            int currD = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (dist[r][c] < currD) continue;

            for (int i = 0; i < 4; i++) {
                int nextRow = r + dx[i];
                int nextCol = c + dy[i];

                if ( (0 <= nextRow and nextRow < m) and (0 <= nextCol and nextCol < n) ) {
                    int time = max(grid[nextRow][nextCol], currD);

                    if (time < dist[nextRow][nextCol]) {
                        dist[nextRow][nextCol] = time;
                        pq.push({dist[nextRow][nextCol], {nextRow, nextCol}});
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }

    int swimInWater(vector<vector<int>>& grid) {
        return dijkstra(grid);
    }
};