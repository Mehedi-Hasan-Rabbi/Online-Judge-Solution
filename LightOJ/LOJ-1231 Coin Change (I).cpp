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
 
const double PI = 3.14159265358979323846;
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

const int mod = 100000007; // 1e8 + 7
int n, k;
int coin[55], can_use[55];
int dp[55][1005];

int possible_ways (int idx, int total) {
    if (idx == n or total == 0) {
        if (total == 0) return 1;
        else return 0;
    }
    if (dp[idx][total] != -1) return dp[idx][total];

    int ans = 0;
    for (int i = 0; i <= can_use[idx]; i++) {
        if ( (total - (i * coin[idx])) >= 0 )
            ans += (possible_ways(idx + 1, (total - (i * coin[idx]))) % mod);
        else
            break;
    }

    return dp[idx][total] = ans % mod;
}

void solve()
{
    memset(dp, -1, sizeof(dp));

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> coin[i];
    for (int i = 0; i < n; i++) cin >> can_use[i];


    int ans = possible_ways(0, k);
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