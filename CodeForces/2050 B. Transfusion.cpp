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
    ll n; cin >> n;
    vector<ll> a(n, 0);

    for (int i = 0; i < n; i++) cin >> a[i];

    ll tot = accumulate(a.begin(), a.end(), 0LL);

    if (tot % n != 0) {
        cout << "NO" << endl;
        return;
    }

    ll x = tot / n;

    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] < x) {
            ll val = abs(a[i - 1] - x);

            a[i - 1] += val;
            a[i + 1] -= val; 
        }
        else if (a[i - 1] > x) {
            ll val = abs(a[i - 1] - x);

            a[i - 1] -= val;
            a[i + 1] += val; 
        }
    }

    if (count(a.begin(), a.end(), a[0]) == n) cout << "YES" << endl;
    else cout << "NO" << endl;
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