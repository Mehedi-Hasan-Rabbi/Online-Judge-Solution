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

const int mx = 1e2 + 123;
vector<bool> vis(mx, false), isNode(mx, false);
vector<int> adj[mx];

void dfs (int node)
{
    vis[node] = true;

    for (auto &&u: adj[node]) {
        if (vis[u] == false)
            dfs(u);
    }
    return;
}

void solve()
{
    int n, m; cin >> n >> m;
    int ans = 0;

    for (int i = 1; i <= n; i++) 
    {
        int k; cin >> k;
        
        if (k == 0) ans++;
        else if (k == 1)
        {
            int u; cin >> u;
            adj[u].push_back(u);
            isNode[u] = true;
        }
        else 
        {
            int v = -1;
            while (k--) 
            {
                int u; cin >> u;
                if (v == -1) v = u;
                else 
                {
                    adj[v].push_back(u);
                    adj[u].push_back(v);

                    isNode[u] = true;
                    isNode[v] = true;
                    v = u;
                }
            }
        }
    }

    int connected_component = 0;
    for (int node = 1; node <= m; node++)
    {
        if (vis[node] == false and isNode[node] == true) {
            connected_component++;
            dfs(node);
        }
    }
    
    ans = ans + max(connected_component - 1, 0);
    cout << ans << endl;
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