// In the name of Allah, the merciful.
#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#ifndef ONLINE_JUDGE
#include "algo/Debug.h"
#else
#define dbg(...)
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // *X.find_by_order(n), X.order_of_key(n), *X.lower_bound(n), *X.upper_bound(n), X.erase(n)
// less<int> -> Ascending || greater<int> -> Descending || less_equal<int> -> Ascending Multiset || greater_equal<int> -> Descending Multiset
 
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
    int n, q; cin >> n >> q;
    vector<ll> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) {
        if (b[i] > a[i])
            swap(b[i], a[i]);
    }

    ll mx = a[n];
    for (int i = n; i >= 1; i--) {
        mx = max(a[i], mx);
        a[i] = mx;
    }

    for (int i = n; i >= 2; i--) {
        if ( (2LL * b[i]) > (a[i - 1] + a[i]) ) {
            swap(b[i], a[i]);
            a[i - 1] = a[i];
        }
    }

    mx = a[n];
    for (int i = n; i >= 1; i--) {
        mx = max(a[i], mx);
        a[i] = mx;
    }

    vector<ll> pref = a;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + pref[i];
    }

    while (q--) {
        int l, r; cin >> l >> r;
        cout << pref[r] - pref[l - 1] << " ";
    }
    cout << endl;
}
 
int main(void) {
    // efficient();
 
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