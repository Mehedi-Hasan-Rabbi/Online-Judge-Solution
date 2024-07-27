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

ll find_C (ll a, ll b, ll n, ll x) // Upper bound of C using binary search
{
    ll l = 1, r = 1e6;
 
    ll cnt = -1;
    while (l <= r) {
        ll c = l + (r - l) / 2;
 
        ll val_1 = a + b +  c;
        ll val_2 = (a*b) + (a*c) + (b*c);
 
        if (val_1 <= x and val_2 <= n) {
            cnt = c;
            l = c + 1;
        }
        else r = c - 1;
    }
 
    return cnt;
}

void solve()
{
    ll n, x; cin >> n >> x;
    ll ans = 0;

    for (ll a = 1; a <= n; a++)
    {
        for (ll b = 1; (a * b) <= n; b++)
        {
            // ll c = find_C(a, b, n, x);
            // if (c != -1) ans += c;

            // Or, we can simply use (ab + bc + ca <= n) and (a + b + c <= x) eq. to get upper bound
            ll c = min ( ((n - (a * b)) / (a + b)), (x - a - b) );
            if (c >= 1) ans += c;
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