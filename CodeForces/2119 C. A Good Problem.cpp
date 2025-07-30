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
    ll n, l, r, k; cin >> n >> l >> r >> k;

    // For odd number of element we can fill the array with lowest number l
    // Because, XOR and AND operation of odd number od element is the number itslef.
    if (n % 2 == 1) {
        cout << l << endl;
        return;
    }

    vector<bool> bin_l(62, 0);
    ll val = 0;
    for (ll bit = 0; bit < 62; bit++) {
        if (l & (1LL << bit)) {
            bin_l[bit] = true;
            val = bit;
        }
    }

    val = (1LL << (val + 1));
    
    if (!(l <= val and val <= r) or n == 2) {
        cout << -1 << endl;
        return;
    }

    // For even number of element we can fill 1 to (n - 2) element with l
    // and fill last two element with lowest element which has one extra set bit than l and all other bit is unset
    ll ans_l = l, ans_r = val;

    if (k <= n - 2) cout << ans_l << endl;
    else cout << ans_r << endl;
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