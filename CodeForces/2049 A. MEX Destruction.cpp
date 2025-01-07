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
    int n; cin >> n;
    vector<int> a(n + 1, 0), prefZero(n + 1, 0), prefOne(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        if (a[i] == 0) prefZero[i] = 1;
        if (a[i] == 1) prefOne[i] = 1;
    }

    for (int i = 1; i <= n; i++) prefZero[i] = prefZero[i - 1] + prefZero[i];
    for (int i = 1; i <= n; i++) prefOne[i] = prefOne[i - 1] + prefOne[i];

    int ans = 2;
    if (prefZero[n] - prefZero[0] == n) ans = 0;
    else if (prefZero[n] - prefZero[0] == 0) ans = 1;
    else {
        int l = 1, r = n;
        while (l <= r) {
            if (a[l] == 0) l++;
            if (a[r] == 0) r--;

            if (a[l] != 0 and a[r] != 0) break;
        }
        int zero = prefZero[r] - prefZero[l - 1];
        int one = prefOne[r] - prefOne[l - 1];

        if (zero == 0) ans = 1;
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