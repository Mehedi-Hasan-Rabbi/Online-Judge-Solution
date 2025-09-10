// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<pair<int, int>> adj[V];
        for (auto ed: edges) {
            int u = ed[0];
            int v = ed[1];
            int w = ed[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> dist(V + 5, INT32_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, src});
        dist[src] = 0;
        
        while (!pq.empty()) {
            int currDistance = pq.top().first;
            int currNode = pq.top().second;
            pq.pop(); 
            
            if (dist[currNode] < currDistance) continue;
            
            for (auto p: adj[currNode]) {
                int v = p.first;
                int w = p.second;
                
                if (currDistance + w < dist[v]) {
                    dist[v] = currDistance + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < V; i++)
            ans.push_back(dist[i]);
            
        return ans;
    }
};
// Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1