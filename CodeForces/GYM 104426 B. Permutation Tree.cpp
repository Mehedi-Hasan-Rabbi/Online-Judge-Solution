// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef unsigned long long ull;

#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);

int dx[] = {+1, -1, 0, 0, +1, +1, -1, -1};
int dy[] = {0, 0, -1, +1, +1, -1, +1, -1};

const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

const int mx = 2e5 + 123;
vector<int> adj[mx];
vector<int> level(mx), vis(mx), vis_2(mx), val(mx), parent(mx);

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();
        for (auto child : adj[cur_v])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                level[child] = level[cur_v] + 1;
            }
        }
    }
}

void dfs(int vertex, int par)
{
    parent[vertex] = par;
    vis_2[vertex] = 1;
    for(int child: adj[vertex])
    { 
        if (vis_2[child] == 0)
            dfs(child, vertex);
    }
}

void solve()
{
    int n, x; cin >> n >> x;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(x);
    dfs(x, -1);

    val[x] = 1;

    int prev = 1;
    for (int i = 1; i <= n; i++)
    {
        if (val[i] == 0)
        {
            vector<int> path;

            int child = i;
            while (val[parent[child]] == 0) {
                path.push_back(parent[child]);
                child = parent[child];
            }

            val[i] = path.size() + 1 + prev;
            prev = max(val[i], prev);

            int curr = val[i] - 1;
            for (auto u: path) {
                val[u] = curr;
                curr--;
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
        cout << val[i] << " ";
}

signed main(void) {
    efficient();

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}