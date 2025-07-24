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

ll good_numbers (ll n) {
    // All number which is divisible by 2 or 3 or 5 or 7 or multiple of themsleves are consider bad number
    ll ans = 0;
    for (ll a2 = 0; a2 < 2; a2++) {
        for (ll a3 = 0; a3 < 2; a3++) {
            for (ll a5 = 0; a5 < 2; a5++) {
                for (ll a7 = 0; a7 < 2; a7++) {
                    int cnt = 0;
                    ll div = 1;

                    if (a2) div *= 2, cnt++;
                    if (a3) div *= 3, cnt++;
                    if (a5) div *= 5, cnt++;
                    if (a7) div *= 7, cnt++;

                    if (cnt % 2 == 0) ans += (n / div);
                    else ans -= (n / div);
                }
            }
        }
    }

    return ans;
}

void solve()
{
    ll l, r; cin >> l >> r;

    ll ans = good_numbers(r) - good_numbers(l - 1LL);
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

// Editorial: https://youtu.be/68fdAqE4FyA?t=1334