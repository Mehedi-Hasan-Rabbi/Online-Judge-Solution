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
    vector<int> a(n, 0);
    vector<vector<int>> bits(n, vector<int>(35, 0));
    vector<int> cnt(35, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int b = 0; b < 32; b++) {
            if (a[i] & (1 << b)) {
                cnt[b]++;
                bits[i][b] = 1;
            }
        }
    }

    ll ans = -1;
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int b = 0; b < 32; b++) {
            ll val = 1 << b;
            if (bits[i][b] == 0) {
                sum += (val * cnt[b]);
            }
            else {
                sum += (val * (n - cnt[b]));
            }
        }

        ans = max(sum, ans);
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