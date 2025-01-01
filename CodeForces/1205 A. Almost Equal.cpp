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
    vector<int> a(2 * n, 0);

    int val = 1;
    for (int i = 0; i < n; i++) {
        if (val % 2 == 1) {
            a[i] = (val * 2) - 1;
            a[i + n] = (val * 2);
        }
        else {
            a[i] = (val * 2);
            a[i + n] = (val * 2) - 1;
        }
        val++;
    }

    set<int> dif;
    ll sum = accumulate(a.begin(), a.begin() + n, 0);
    dif.insert(sum);
    int l = 0, r = n - 1;
    while (l < n) {
        sum -= a[l];
        l++, r++;
        sum += a[r];

        dif.insert(sum);
    }

    sum -= a[l]; sum += a[0]; dif.insert(sum);

    if (dif.size() == 2 and abs( *dif.begin() - *dif.rbegin() ) == 1) {
        cout << "YES" << endl;
        for (auto u: a)
            cout << u << " ";
        cout << endl;
    }
    else cout << "NO" << endl;
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