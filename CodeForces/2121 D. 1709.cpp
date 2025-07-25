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

void move (vector<int>& v, int val, int pos, int op, vector<pair<int, int>>& ans) {
    int idx = find(v.begin(), v.end(), val) - v.begin();
    
    if (idx == pos) return;

    while (idx > pos) {
        swap (v[idx - 1], v[idx]);
        ans.push_back({op, idx - 1});
        idx--;
    }
}

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<pair<int, int>> ans;
    int up = 1, down = 2;

    for (int i = 1; i <= n; i++) {
        // Put up in right position
        int idx = find(b.begin(), b.end(), up) - b.begin();
        if (idx <= n) {
            swap(a[idx], b[idx]);
            ans.push_back({3, idx});
        }
        move (a, up, i, 1, ans);
        up = up + 2;

        // Put down in right position
        idx = find(a.begin(), a.end(), down) - a.begin();
        if (idx <= n) {
            swap(a[idx], b[idx]);
            ans.push_back({3, idx});
        }
        move (b, down, i, 2, ans);
        down = down + 2;
    }

    cout << ans.size() << endl;
    for (auto u: ans) cout << u.first << " " << u.second << endl;
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