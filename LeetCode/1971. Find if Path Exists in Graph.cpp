class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> adj;

    void dfs (int node) {
        vis[node] = true;

        for (auto u: adj[node]) {
            if (vis[u] == false)
                dfs(u);
        }
        return;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int mx = 2e5 + 123;
        vis.resize(mx); adj.resize(mx);

        for (auto &e: edges) {
            int u = e[0], v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(source);

        if (vis[destination]) return true;
        else return false;
    }
};