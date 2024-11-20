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
    ll n, total; cin >> n >> total;
    vector<ll> a(n + 1, 0LL), pref(n + 1, 0LL);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    if (pref.back() <= total) {
        cout << "infinite" << endl;
        return;
    }

    ll ans = 0;
    ll low = 0, high = 1e9;
    while (low <= high) {
        ll mid = low + (high - low) / 2LL;

        int idx = upper_bound(a.begin(), a.end(), mid) - a.begin();

        ll curr = pref[idx - 1];
        if (idx <= n) {
            curr += ((n - idx + 1LL) * mid);
        }

        if (curr <= total) {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else 
            high = mid - 1;
    }

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