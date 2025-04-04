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
 
void solve()
{
    int n; cin >> n;
    vector<int> p(n + 1, 0), d(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> d[i];

    vector<int> group(n + 1, 0);
    vector<bool> vis(n + 1, false);
    int tot_grp = 1;

    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            int idx = i;
            
            while (vis[idx] != true) {
                vis[idx] = true;
                group[idx] = tot_grp;
                idx = p[idx];
            }
            tot_grp++;
        }
    }
    
    vector<int> group_mem(n + 1, 0);
    for (int i = 1; i <= n; i++)
        group_mem[group[i]]++;
    
    vector<bool> vis_group(n + 1, false);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int grp_number = group[d[i]];
        int members_in_grp = group_mem[grp_number];

        if (vis_group[grp_number] == false) {
            ans += members_in_grp;
            vis_group[grp_number] = true;
        }
        cout << ans << " ";
    }
    cout << endl;
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