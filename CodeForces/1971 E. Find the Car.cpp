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

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    ll n, k, q; cin >> n >> k >> q;
    vector<ll> a(k + 1, 0), b(k + 1, 0);
    for (ll i = 1; i <= k; i++) cin >> a[i];
    for (ll i = 1; i <= k; i++) cin >> b[i];

    while (q--) {
        ll d; cin >> d;
        
        ll idx = upper_bound(a.begin(), a.end(), d) - a.begin();
        ll distance = abs(a[idx - 1] - a[idx]);
        ll time = abs(b[idx - 1] - b[idx]);

        ll ans = b[idx - 1];
        ll extra = abs(a[idx - 1] - d);

        ans = ans + ( extra * time / distance );

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