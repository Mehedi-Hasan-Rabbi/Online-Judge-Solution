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

int dp[300005];
vector<vector<pair<int, int>>> tree;
vector<bool> vis;

int dfs (int idx) {
    // If both left and right child is Node 0 then leaf node
    if (tree[idx][0].first == 0 and tree[idx][1].first == 0) return 0;
    if (dp[idx] != -1) return dp[idx];

    vis[idx] = true;
    int res = INT32_MAX;

    // explore only left and right children (not parent)
    for (int i = 0; i < 2; i++) {
        // tree[idx][i].first == 0 means no child
        if (tree[idx][i].first != 0 and vis[tree[idx][i].first] == false) {
            int val = tree[idx][i].second + dfs(tree[idx][i].first);
            res = min(res, val);
        }
    }

    dp[idx] = res;
    return dp[idx];
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    tree.clear();
    vis.clear();

    int n; cin >> n;
    string s; cin >> s;
    s = "#" + s;

    tree.resize(n + 5, vector<pair<int, int>>(3));
    vis.resize(n + 5, false);
    // tree[v] holds 3 edges: [0] = left child, [1] = right child, [2] = parent

    for (int i = 1; i <= n; i++) {
        pair<int, int> left, right;
        cin >> left.first;      // Left node
        cin >> right.first;     // Right node

        // Both node initial weight
        left.second = 1;
        right.second = 1;

        // if the node's instruction (s-string) matches the edge direction, cost = 0
        if (s[i] == 'L') {
            left.second = 0;
        } 
        else if (s[i] == 'R') {
            right.second = 0;
        }

        // Assign Parent nodes left child and right child.
        tree[i][0] = left;
        tree[i][1] = right;

        // Assign left, right childs parent.
        tree[left.first][2] = {i, left.second};
        tree[right.first][2] = {i, right.second};
    }

    cout << dfs(1) << endl;

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