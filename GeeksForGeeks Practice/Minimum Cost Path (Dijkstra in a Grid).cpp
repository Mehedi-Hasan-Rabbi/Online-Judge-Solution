class Solution {
public:
    vector<int> dx = {+1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, +1};

    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n+1, vector<int>(m+1, INT32_MAX));
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        // Where I am staring/stading also costs.
        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        while(!pq.empty()) {
            int currD = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (dist[row][col] < currD) continue;

            for (int i = 0; i < 4; i++) {
                int nextRow = row + dx[i];
                int nextCol = col + dy[i];

                if ( (0 <= nextRow and nextRow < n) and (0 <= nextCol and nextCol < m) ) {
                    int w = grid[nextRow][nextCol];

                    if (currD + w < dist[nextRow][nextCol]) {
                        dist[nextRow][nextCol] = currD + w;
                        pq.push({dist[nextRow][nextCol], {nextRow, nextCol}});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};
// Link: https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1