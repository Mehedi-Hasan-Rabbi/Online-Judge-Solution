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
 
void solve()
{
    ll k, l, r, a, b; 
    cin >> k >> l >> r >> a >> b;

    ll ans = 0, pow = 1LL;

    while (pow <= 1e9)
    {
        ll start = -1, last = -1;

        ll low = l, high = r;
        while (low <= high) {
            ll mid = low + (high - low) / 2LL;

            ll val = mid * pow;

            if (val >= a and val <= b) {
                start = mid;
                high = mid - 1;
            }

            if (val > b) high = mid - 1;
            else if (val < a) low = mid + 1;
        }

        low = l, high = r;
        while (low <= high) {
            ll mid = low + (high - low) / 2;

            ll val = mid * pow;

            if (val >= a and val <= b ) {
                last = mid;
                low = mid + 1;
            }

            if (val > b) high = mid - 1;
            else if (val < a)  low = mid + 1;
        }

        if (start != -1 and last != -1) {
            ans += (last - start + 1);
        }

        pow *= k;
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