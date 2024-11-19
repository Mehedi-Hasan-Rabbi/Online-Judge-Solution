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
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}
 
/*---------------------------------------------------------------------------------------------------------------*/

ll Modular_Addition(ll x, ll y) {
    x = x % mod; y = y % mod;
    return (((x + y) % mod) + mod) % mod;
}

const int mx = 1e6 + 123;
ll dp[mx];
ll n;

ll diceCombinations (ll currSum) 
{
    if (currSum == n) return 1;
    if (dp[currSum] != -1) return dp[currSum];

    ll take = 0;
    for (int dice = 1; dice <= 6; dice++) {
        if (currSum + dice <= n) {
            take = Modular_Addition(take, diceCombinations(currSum + dice));
        }
    }

    return dp[currSum] = take;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;

    ll ans = diceCombinations(0);
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