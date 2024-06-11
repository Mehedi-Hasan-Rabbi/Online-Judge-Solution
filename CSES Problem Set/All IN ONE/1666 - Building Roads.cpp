// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/Debug.h"
#else
#define dbg(...)
#endif

typedef long long ll;
typedef unsigned long long ull;

#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
#define fraction()         cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return abs(a) * ( abs(b) / gcd ( a, b ) ); }

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

const int mx = 1e5 + 123;
vector<bool> vis(mx, false);
vector<int> adj[mx];

void dfs (int node)
{
    vis[node] = true;

    for (auto &&u: adj[node]) {
        if (vis[u] == false)
            dfs(u);
    }
}

void solve()
{
    int n, m; cin >> n >> m;

    for (int i = 0; i <= m; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> start; // Store the starting point of all connected component
    for (int node = 1; node <= n; node++)
    {
        if (vis[node] == false) {
            start.push_back(node);
            dfs(node);
        }
    }
    
    cout << start.size() - 1 << endl;
    for (int i = 0; i < start.size() - 1; i++) {
        cout << start[i] << " " << start[i + 1] << endl;
    }
}

int main(void) {
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