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
    ll n, m; cin >> n >> m;
    ll horizontal = 0, vertical = 0;

    vector<int> x(n + 1, 0), y(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];

        x[i] = x[i - 1] + x[i];
        y[i] = y[i - 1] + y[i];
    }

    ll prev = x[1];
    for (int i = 1; i <= n; i++) {
        ll sum = x[i] + m;
        horizontal += (sum - prev);

        prev = sum;
    }

    prev = y[1];
    for (int i = 1; i <= n; i++) {
        ll sum = y[i] + m;
        vertical += (sum - prev);

        prev = sum;
    }

    ll ans = (horizontal * 2) + (vertical * 2);
    cout << ans << endl;
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