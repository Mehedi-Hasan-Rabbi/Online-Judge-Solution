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
    ll n, x; cin >> n >> x;
    vector<ll> a(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll> pref = a;
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + pref[i];
    
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ll val = pref[i];

        ll day_start = 0, day_end = 1e9 + 5;
        ll until_day = -1;
        
        while (day_start <= day_end) {
            ll mid = day_start + (day_end - day_start) / 2;

            ll curr = pref[i] + (mid * i);

            if (curr <= x) {
                until_day = mid;
                day_start = mid + 1;
            }
            else day_end = mid - 1;
        }
        if (until_day >= 0) ans += until_day + 1;
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