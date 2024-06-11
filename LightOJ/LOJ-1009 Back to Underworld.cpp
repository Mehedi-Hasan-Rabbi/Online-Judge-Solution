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

const int mx = 2e4 + 123;
vector<bool> vis(mx, false), sigleNode(mx, true);
vector<int> adj[mx];
int total = 0, blue = 0, red = 0;

void dfs (int node, char colour) {
    vis[node] = true;
    if (colour == 'B') blue++;
    total++;

    char temp;
    if (colour == 'B') temp = 'R';
    else temp = 'B';

    for (auto &&u: adj[node]) {
        if (vis[u] == false) {
            dfs (u, temp);
        }
    }
}

void solve()
{
    // Clear all previous data
    for (int i = 1; i <= 2e4; i++) {
        adj[i].clear();
        vis[i] = false;
        sigleNode[i] = true;
    }

    // Start
    int edge; cin >> edge;

    for (int i = 1; i <= edge; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        sigleNode[u] = false;
        sigleNode[v] = false;
    }

    int ans = 0;
    for (int node = 1; node <= 2e4; node++) {
        // We can't take any single node. Becouse, fight must require more than 1 person(node).
        if (sigleNode[node] == false and vis[node] == false) {
            total = 0, blue = 0, red = 0;
            dfs(node, 'B');

            red = total - blue;
            ans += max(blue, red);
        }
    }

    cout << ans << endl;
}

int main(void) {
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}