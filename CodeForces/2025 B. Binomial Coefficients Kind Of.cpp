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

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

const int mx = 1e5 + 123;
int dp[mx];

void solve()
{
    int t; cin >> t;
    vector<int> n(t, 0), k(t, 0);
    for (auto &u: n) cin >> u;
    for (auto &u: k) cin >> u;
    
    for (int i = 0; i < t; i++) {
        if (n[i] == k[i]) cout << 1 << endl;
        else cout << dp[k[i]] << endl;
    }
}

int main(void) {
    efficient();
    
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i < mx; i++) {
        dp[i] = ((dp[i - 1] % MOD) * (2 % MOD)) % MOD;
    }

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