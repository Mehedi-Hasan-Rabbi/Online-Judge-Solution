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
 
int dx[] = {+1, -1, 0, 0, +1, +1, -1, -1};
int dy[] = {0, 0, -1, +1, +1, -1, +1, -1};
 
const ll mod = 1e9 + 7; // 1000000007;
const double PI = 3.14159265358979323846;
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}
 
/*---------------------------------------------------------------------------------------------------------------*/

// We know that tree is one single connected component
// So, if one node is removed than the number of connected component is equal to the degree of that removed node.
// Now, when we delete second node than,
// if, second node is "not adjacent" with first node then connected component = degree[firstNode] + degree[secondNode] - 1;
// if, second node is "adjacent" with first node then connected component = degree[firstNode] + degree[secondNode] - 2;
// try this drawing a tree with pen and paper.

void solve()
{
    int n; cin >> n;
    set<pair<int, int>> tree_edge;
    vector<int> deg(n + 1, 0);

    for (int edge = 1; edge < n; edge++) {
        int u, v; cin >> u >> v;
        
        tree_edge.insert({u, v});
        tree_edge.insert({v, u});

        deg[u]++, deg[v]++;
    }

    vector<pair<int, int>> degree;
    for (int node = 1; node <= n; node++)
        degree.push_back({deg[node], node});
    
    sort(degree.begin(), degree.end(), greater<pair<int, int>>());

    int ans = 0;
    // Check maximum from adjacent node
    for (auto u: tree_edge) {
        int val = deg[u.first] + deg[u.second] - 2;
        ans = max(ans, val);
    }

    // Check maximum from not adjacent node
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // there is no edge between two node
            if (tree_edge.find({degree[i].second, degree[j].second}) == tree_edge.end())
            { 
                int val = degree[i].first + degree[j].first - 1;
                ans = max(ans, val);
                break;
            }
        }
    }

    cout << ans << endl;
}
 
int main(void) {
    efficient();
 
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
 
    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}