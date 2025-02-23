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
    int n; cin >> n;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (a[n - 1] > a[n]) {
        cout << -1 << endl;
        return;
    }

    vector<int> ans;
    a[0] = INT64_MIN;
    ll val = a[n - 1] - a[n];
    for (int i = 1; i <= n - 2; i++) {
        if (a[i - 1] <= min(a[i], val)) {
            a[i] = min(a[i], val);

            if (min(a[i], val) == val) ans.push_back(i);
        }
        else if (a[i - 1] <= max(a[i], val)) {
            a[i] = max(a[i], val);

            if (max(a[i], val) == val) ans.push_back(i);
        }
        else {
            cout << -1 << endl;
            return;
        }
    }

    if (is_sorted(a.begin() + 1, a.end())) {
        cout << ans.size() << endl;
        for (auto u: ans) {
            cout << u << " " << n - 1 << " " << n << endl;
        }
    }
    else cout << -1 << endl;
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